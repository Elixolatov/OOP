using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public sealed class EnemyZombieScr : EnemyScr
{
    protected sealed override void Start()
    {
        WayPoints = GameObject.Find("LevelGroup").GetComponent<LevelManagerScr>().WayPoints;
        Health = 100;
        Speed = 4;
    }
}
