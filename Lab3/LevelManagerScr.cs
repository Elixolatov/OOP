using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelManagerScr : MonoBehaviour
{
    int FieldWidth = 13, FieldHight = 8, currentWayX, currentWayY;
    [SerializeField] GameObject CellPref;
    [SerializeField] Transform CellParent;
    [SerializeField] Sprite[] TitleSpr = new Sprite[2];

    GameObject[,] allCells = new GameObject[13, 8];
    List<GameObject> wayPoints = new List<GameObject>();

    public List<GameObject> WayPoints { get{ return wayPoints; } }

    GameObject firstCell=null;

    int[] path = {0,0,1,0,0,0,0,0,0,0,0,0,0,
                  0,0,1,0,0,0,0,0,0,0,0,0,0,
                  0,0,1,0,0,0,0,0,0,1,1,1,1,
                  0,0,1,0,0,0,0,0,0,1,0,0,0,
                  0,0,1,1,1,1,0,1,1,1,0,0,0,
                  0,0,0,0,0,1,0,1,0,0,0,0,0,
                  0,0,0,0,0,1,1,1,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,};

    void Start()
    {
        CreateLevel();
    }

    void CreateLevel()
    {
        firstCell = null;

        Vector3 levelVec = Camera.main.ScreenToWorldPoint(new Vector3(0, Screen.height, 0));

        for (int i = 0; i < FieldWidth; i++)
            for (int j = 0; j < FieldHight; j++)
            {
                int sprIndex = path[j* FieldWidth + i];
                Sprite spr = TitleSpr[sprIndex];

                bool IsRoad;
                if (sprIndex == 1)
                    IsRoad = true;
                else
                    IsRoad = false;

                CreateCell(IsRoad ,spr, i, j, levelVec);
            }
        CreateWayPoints();
    }


    void CreateCell(bool IsRoad, Sprite spr, int i, int j, Vector3 levelVec)
    {
        GameObject tmpCell = Instantiate(CellPref);

        tmpCell.transform.SetParent(CellParent, false);

        tmpCell.GetComponent<SpriteRenderer>().sprite = spr;
        float SpriteSizeX = tmpCell.GetComponent<SpriteRenderer>().bounds.size.x;
        float SpriteSizeY = tmpCell.GetComponent<SpriteRenderer>().bounds.size.y;
        tmpCell.transform.position = new Vector3(levelVec.x + (SpriteSizeX * i), levelVec.y + (SpriteSizeY * -j));

        if(IsRoad)
        {
            tmpCell.GetComponent<Cell>().IsRoad = true;
            if(firstCell==null)
            {
                firstCell = tmpCell;
                currentWayX = i;
                currentWayY = j;
            }
        }
        allCells[i, j] = tmpCell;
    }

    void CreateWayPoints()
    {
        GameObject currWayGo;

        wayPoints.Add(firstCell);

        while (true)
        {
            currWayGo = null;
            if (currentWayX > 0 && allCells[currentWayX - 1, currentWayY].GetComponent<Cell>().IsRoad &&
                !wayPoints.Exists(x => x == allCells[currentWayX - 1, currentWayY]))
            {
                currWayGo = allCells[currentWayX - 1, currentWayY];
                currentWayX--;
            }
            else if (currentWayX < (FieldWidth - 1) && allCells[currentWayX + 1, currentWayY].GetComponent<Cell>().IsRoad &&
                !wayPoints.Exists(x => x == allCells[currentWayX + 1, currentWayY]))
            {
                currWayGo = allCells[currentWayX + 1, currentWayY];
                currentWayX++;
            }
            else if (currentWayY > 0 && allCells[currentWayX, currentWayY - 1].GetComponent<Cell>().IsRoad &&
                !wayPoints.Exists(x => x == allCells[currentWayX, currentWayY - 1]))
            {
                currWayGo = allCells[currentWayX, currentWayY - 1];
                currentWayY--;
            }
            else if (currentWayY < (FieldHight - 1) && allCells[currentWayX, currentWayY + 1].GetComponent<Cell>().IsRoad &&
                !wayPoints.Exists(x => x == allCells[currentWayX, currentWayY + 1]))
            {
                currWayGo = allCells[currentWayX, currentWayY + 1];
                currentWayY++;
            }
            else
                break;
            wayPoints.Add(currWayGo);
        }
    }
}
