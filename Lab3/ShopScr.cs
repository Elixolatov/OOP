using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class ShopScr : MonoBehaviour
{
    [SerializeField] GameObject ItemPref;
    [SerializeField] Transform ItemGrid;
    public Cell selfCell;

    void Start()
    {
        for (int i=0;i< GameManagerScr.Instance.Tower.Length;i++)
        {
            GameObject tmpItem = Instantiate(ItemPref);
            tmpItem.transform.SetParent(ItemGrid, false);
            tmpItem.GetComponent<ShopItemScr>().SetStartData(GameManagerScr.Instance.AllTowers[i], selfCell, i);
        }
    }

    public void CloseShop()
    {
        Destroy(gameObject);
    }

}
