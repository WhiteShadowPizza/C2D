#pragma once

/*** Clear�N���X ***/
class
{
public:
	int Out()
	{
		int ret = SCE::SCE_02_CLE;

		/*** �N���A��ʂ̕`�� ***/
		DrawGraph(0, 0, Pic.Clear, TRUE);

		/*** Press Enter�̕`�� ***/
		DrawFormatStringFToHandle(CLE_ENTER_POS_X, CLE_ENTER_POS_Y, Col.White, Fon.FH[30], "Press Space");

		/*** �N���A�^�C���̕`�� ***/
		for (int i = 0; i < RANK_DISP_NUM; i++)
		{
			DrawFormatStringFToHandle(RANK_POS_X, static_cast<float>(RANK_POS_Y + i * 10), Col.White, Fon.FH[10], "No.%d:%6.2f s", i + 1, Sta.Rank[i]);
		}

		/*** �^�C�g���V�[���Ɉڍs ***/
		if ((Key.input[KEY_INPUT_SPACE] > 0)		// Space����
			)
		{
			Sta.StartCount = GetNowCount(); // �J�n�J�E���g�ݒ�
			ret = SCE::SCE_00_TIT; // �^�C�g���V�[���Ɉڍs
		}
		return ret;
	}

private:

}Cle;