#pragma once

/*** Clearクラス ***/
class
{
public:
	int Out()
	{
		int ret = SCE::SCE_02_CLE;

		/*** クリア画面の描画 ***/
		DrawGraph(0, 0, Pic.Clear, TRUE);

		/*** Press Enterの描画 ***/
		DrawFormatStringFToHandle(CLE_ENTER_POS_X, CLE_ENTER_POS_Y, Col.White, Fon.FH[30], "Press Space");

		/*** クリアタイムの描画 ***/
		for (int i = 0; i < RANK_DISP_NUM; i++)
		{
			DrawFormatStringFToHandle(RANK_POS_X, static_cast<float>(RANK_POS_Y + i * 10), Col.White, Fon.FH[10], "No.%d:%6.2f s", i + 1, Sta.Rank[i]);
		}

		/*** タイトルシーンに移行 ***/
		if ((Key.input[KEY_INPUT_SPACE] > 0)		// Space押下
			)
		{
			Sta.StartCount = GetNowCount(); // 開始カウント設定
			ret = SCE::SCE_00_TIT; // タイトルシーンに移行
		}
		return ret;
	}

private:

}Cle;