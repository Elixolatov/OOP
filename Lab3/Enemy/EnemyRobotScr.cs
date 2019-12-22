using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public sealed class EnemyRobotScr : EnemyScr
{

    protected sealed override void  Start()
    {
        WayPoints = GameObject.Find("LevelGroup").GetComponent<LevelManagerScr>().WayPoints;
        Health = 200;
        Speed = 1;
    }
}
