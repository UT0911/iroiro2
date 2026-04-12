#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1) //DXライブラリ初期化処理
	{
		return -1; //エラーが起きたら直ちに終了
	}

	ChangeWindowMode(true); //ウィンドウモード設定
	SetGraphMode(800, 800, 32); //ウィンドウサイズ、解像度設定
	SetMouseDispFlag(true); //マウス表示設定
	SetFontSize(60); //フォントサイズ設定

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//処理を書く
		ClearDrawScreen(); //画面を初期化
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Hello World!"); //文字の描画
		ScreenFlip(); //画面更新
	}


	DxLib_End(); //DXライブラリ使用の終了処理

	return 0; //ソフトの終了 
}