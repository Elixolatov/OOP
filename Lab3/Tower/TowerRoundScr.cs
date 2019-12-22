using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TowerRoundScr : MonoBehaviour
{
    Transform target;
    float speed = 10;
    int Damage;

    void Update()
    {
        Move();
    }

    public void SetTarget(Transform Enemy,int damage)
    {
        target = Enemy;
        Damage = damage;
    }

    void Move()
    {
        if(target!=null)
        {
            if (Vector2.Distance(transform.position, target.position) < .1f)
            {
                target.GetComponent<EnemyScr>().TakeDamage(Damage);
                Destroy(gameObject);
            }
            else
            {
                Vector2 dir = target.position - transform.position;
                transform.Translate(dir.normalized * Time.deltaTime * speed);
            }
        }
        else
            Destroy(gameObject);
    }
}
