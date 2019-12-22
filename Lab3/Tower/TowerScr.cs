using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class TowerScr : MonoBehaviour
{
    [SerializeField] GameObject Round;
    float CurrCoolDown=0;

    protected float range, CoolDown;
    protected int Damage;
    public int price;

    protected virtual void Start()
    {

    }

    protected virtual void Update()
    {
        if (CurrCoolDown <= 0)
            SearchTarget();

        if (CurrCoolDown > 0)
            CurrCoolDown -= Time.deltaTime;
    }

    void SearchTarget()
    {
        Transform nearestEnemy = null;
        float nearstEnemyDistance = Mathf.Infinity;

        foreach(GameObject enemy in GameObject.FindGameObjectsWithTag("Enemy"))
        {
            float currDistance = Vector2.Distance(transform.position, enemy.transform.position);
            if (currDistance < nearstEnemyDistance && currDistance<= range)
            {
                nearestEnemy = enemy.transform;
                nearstEnemyDistance = currDistance;
            }
        }
        if (nearestEnemy != null)
            Shoot(nearestEnemy);
    }

    void Shoot(Transform enemy)
    {
        CurrCoolDown = CoolDown;
        GameObject proj = Instantiate(Round);
        proj.transform.position = transform.position;
        proj.GetComponent<TowerRoundScr>().SetTarget(enemy, Damage);
    }
}
