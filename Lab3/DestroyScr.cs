using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyScr : MonoBehaviour
{
    public Cell selfCell;

    void DestroyTower()
    {
        selfCell.DestroyTower();
        Destroy(gameObject);
    }

    void Cancel()
    {
        Destroy(gameObject);
    }
}
