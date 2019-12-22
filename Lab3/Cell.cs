using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cell : MonoBehaviour
{
    bool isRoad=false;
    public bool IsRoad
    {   get { return isRoad; }
        set { isRoad = value; } }

    [SerializeField] Color BaseColor, CurrColor, TowerColor;
    [SerializeField] GameObject ShopPref,DestroyPref,SelfTower;

    void OnMouseEnter()
    {
        if(!isRoad && FindObjectsOfType<ShopScr>().Length==0 && FindObjectsOfType<DestroyScr>().Length == 0)
        {
            if(!SelfTower)
            {
                GetComponent<SpriteRenderer>().color = CurrColor;
            }
            else
            {
                GetComponent<SpriteRenderer>().color = TowerColor;
            }
        }
    }

    void OnMouseExit()
    {
        GetComponent<SpriteRenderer>().color = BaseColor;
    }

    void OnMouseDown()
    {
        if (!isRoad && FindObjectsOfType<ShopScr>().Length == 0 && FindObjectsOfType<DestroyScr>().Length == 0)
        {
            if (!SelfTower)
            {
                GameObject tmpShop = Instantiate(ShopPref);
                tmpShop.transform.SetParent(GameObject.Find("Canvas").transform, false);
                tmpShop.GetComponent<ShopScr>().selfCell = this;
            }
            else
            {
                GameObject tmpDes = Instantiate(DestroyPref);
                tmpDes.transform.SetParent(GameObject.Find("Canvas").transform, false);
                tmpDes.GetComponent<DestroyScr>().selfCell = this;
            }
        }
    }

    public void BuildTower(int i)
    {
        GameObject tmpTower = Instantiate(GameManagerScr.Instance.Tower[i]);
        tmpTower.transform.SetParent(transform, false);

        Vector2 TawerPos = new Vector2(transform.position.x + tmpTower.GetComponent<SpriteRenderer>().bounds.size.x, transform.position.y - tmpTower.GetComponent<SpriteRenderer>().bounds.size.y / 3);

        tmpTower.transform.position = TawerPos;

        SelfTower = tmpTower;
        FindObjectOfType<ShopScr>().CloseShop();
    }

    public void DestroyTower()
    {
        GameManagerScr.Instance.Money += SelfTower.GetComponent<TowerScr>().price / 2;
        Destroy(SelfTower);
    }

}
