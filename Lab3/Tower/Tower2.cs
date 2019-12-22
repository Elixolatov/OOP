using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public sealed class Tower2 : TowerScr
{
    protected sealed override void Start()
    {
        range = 5;
        CoolDown = 1;
        Damage = 50;
        price = 20;
    }
}
