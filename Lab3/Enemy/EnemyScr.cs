using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class EnemyScr : MonoBehaviour
{
    protected List<GameObject> WayPoints = new List<GameObject>();

    protected float Speed;
    protected int health;
    public int Health
    { get { return health; }
      set { health = value; } }

    int WayIndex = 0;


    protected virtual void Start()
    {
        WayPoints = GameObject.Find("LevelGroup").GetComponent<LevelManagerScr>().WayPoints;
    }

    protected virtual void Update()
    {
        Move();
    }

    protected virtual void Move()
    {
        Transform currWayPoint = WayPoints[WayIndex].transform;
        Vector3 currWayPo = new Vector3(currWayPoint.position.x + currWayPoint.GetComponent<SpriteRenderer>().bounds.size.x / 2,
            currWayPoint.position.y);

        Vector3 dir = currWayPo - transform.position;

        transform.Translate(dir.normalized * Time.deltaTime * Speed);

        if (Vector3.Distance(transform.position, currWayPo) < 0.3f)
        {
            if (WayIndex < WayPoints.Count - 1)
                WayIndex++;
            else
            {
                Destroy(gameObject);
                GameManagerScr.Instance.Health--;
            }
        }
    }

    public virtual void TakeDamage(int Damage)
    {
        health -=Damage;
        if (health <= 0)
        {
            GameManagerScr.Instance.Money += 10;
            Destroy(gameObject);
        }
    }
}
