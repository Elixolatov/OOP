using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemySpawnerScript : MonoBehaviour
{
    [SerializeField] GameObject[] Enemy = new GameObject[2];
    float TimeSpawn = 5;
    int SpawnCount = 0;

    void Update()
    {
            if (TimeSpawn <= 0)
            {
                StartCoroutine(SpawnEnemy(SpawnCount + 1));
                TimeSpawn = 15;
            }
            TimeSpawn -= Time.deltaTime;
    }

    IEnumerator SpawnEnemy(int EnemyCount)
    {
        SpawnCount++;
        for (int i = 0; i < EnemyCount; i++)
        {
            Transform StarterPos = GameObject.Find("LevelGroup").GetComponent<LevelManagerScr>().WayPoints[0].transform;
            Vector3 StartPosition = new Vector3(StarterPos.position.x + StarterPos.GetComponent<SpriteRenderer>().bounds.size.x / 2, StarterPos.position.y + StarterPos.GetComponent<SpriteRenderer>().bounds.size.y);

            GameObject tmpEnemy = Instantiate(Enemy[Random.Range(0, Enemy.Length)]);
            tmpEnemy.transform.SetParent(gameObject.transform, false);

            tmpEnemy.transform.position = StartPosition;

           yield return new WaitForSeconds(0.5f);
        }
    }
}
