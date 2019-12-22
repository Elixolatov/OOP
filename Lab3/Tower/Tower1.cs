using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public sealed class Tower1 : TowerScr
{
    protected sealed override void Start()
    {
        range = 8;
        CoolDown = 3;
        Damage = 100;
        price = 30;
    }
}
