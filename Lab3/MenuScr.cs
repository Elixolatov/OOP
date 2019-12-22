using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class MenuScr : MonoBehaviour
{
    void StartBtn()
    {
        SceneManager.LoadScene(1);
    }

    void ExitBtn()
    {
        Application.Quit();
    }
}
