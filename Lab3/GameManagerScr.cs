using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public struct Tower
{
    public int price;
    public Sprite Spr;
    public string Name;

    public Tower(int price, string Name, string path)
    {
        this.price = price;
        this.Name = Name;

        Spr = Resources.Load<Sprite>(path);
    }

}

public class GameManagerScr : MonoBehaviour
{
    static GameManagerScr instance;
    public static GameManagerScr Instance
    { get { return instance; } }

    [SerializeField] Text MoneyTxt,HealthTxt;

    int money, health;
    public int Money
    { get { return money; }
      set { money = value; } }
    public int Health
    { get { return health; }
      set { health = value; } }

    [SerializeField] GameObject[] tower = new GameObject[2];
    public GameObject[] Tower
    { get { return tower; } }

    List<Tower> allTowers = new List<Tower>();
    public List<Tower> AllTowers
    { get { return allTowers; } }

    void Awake()
    {
        allTowers.Add(new Tower(20, "Быстрая башня", "tower/towerSmallAlt"));
        allTowers.Add(new Tower(30, "Снайперская Башня", "tower/towerSmall"));
    }

    void Start()
    {
        instance = this;
        money = 50;
        health = 100;
    }

    void Update()
    {
        MoneyTxt.text = money.ToString();
        HealthTxt.text = health.ToString();

        if (Input.GetKeyDown(KeyCode.Escape)||health<=0)
        {
            SceneManager.LoadScene(0);
        }
    }
}
