using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System;

public class ShopItemScr : MonoBehaviour,IPointerClickHandler
{
    [SerializeField] Image TowerLogo;
    [SerializeField] Text logo, price;
    Cell selfCell;
    int Type;
    Tower selfTower;

    public void SetStartData(Tower tower, Cell cell,int i)
    {
        selfTower = tower;
        TowerLogo.sprite = tower.Spr;
        logo.text = tower.Name;
        price.text = tower.price.ToString();
        selfCell = cell;
        Type = i;
    }

    public void OnPointerClick(PointerEventData eventData)
    {
               if(GameManagerScr.Instance.Money >= selfTower.price)
               {
                  GameManagerScr.Instance.Money -= selfTower.price;
                  selfCell.BuildTower(Type);
               }
    }
}
