/*** Header File ***/
#define _CRT_SECURE_NO_WARNINGS // C4996������

#include <algorithm>
#include<iostream>

#include "DxLib.h"
#include "ProjConf.h"
#include "Sub.h"
#include "Picture.h"
#include "Stage.h"
#include "Title.h"
#include "Action.h"
#include "Clear.h"
#include "Scene.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	if (DxLib_Init() == -1)							// �c�w���C�u��������������
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	/*** Window Init ***/
	SetWindowText("GHOST HOUSE");					// �E�B���h�E�̃^�C�g��
	SetWindowInitPosition(WIN_POS_X, WIN_POS_Y);	// �E�B���h�E�̈ʒu
	SetGraphMode(WIN_MAX_X, WIN_MAX_Y, 32);			// �E�B���h�E�̃T�C�Y
	SetBackgroundColor(0, 0, 0);				    // �E�B���h�E�̔w�i�F
	SetDrawScreen(DX_SCREEN_BACK);					// �`����ʂ𗠉�ʂɂ���
	SetAlwaysRunFlag(TRUE);							// �E�C���h�E��A�N�e�B�u��Ԃł������𑱍s����

	/*** FPS������ ***/
	Fps.FPSInit();

	/*** Read ***/
	Col.Read();
	Fon.Read();
	Pic.Read();
	Sta.Read();
#ifdef DEF_SOUND_VALID
	Snd.Read();

	/*** BGM�J�n ***/
	Snd.PlayBGMSound();
#endif /* DEF_SOUND_VALID */

	/*** ���[�v���� ***/
	while (ScreenFlip() == 0 &&		// ����ʂ̓��e��\��ʂɔ��f
		ClearDrawScreen() == 0 &&	// ��ʂ�������
		Key.GetKey() == 0 &&		// �L�[�{�[�h���͏��擾
		ProcessMessage() == 0)		// �E�C���h�E�̃��b�Z�[�W������
	{
		/* FPS�v���J�n */
		Fps.FPSCheck();

		/* �V�[���o�� */
		Sce.Out();

		/* FPS�\�� */
		DrawFormatStringFToHandle(FPS_POS_X, FPS_POS_Y, Col.White, Fon.FH[10], "FPS:%5.1f", Fps.Average);


		/* FPSWait */
		Fps.FPSWait();
	}

	WaitKey();						// �L�[���͑҂�

	DxLib_End();					// �c�w���C�u�����g�p�̏I������

	return 0;						// �\�t�g�̏I�� 
}