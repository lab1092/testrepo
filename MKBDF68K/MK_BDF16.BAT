echo off

echo MKBDF68k ROM�t�H���g to BDF�t�H���g�쐬�o�b�`�t�@�C��
echo _
echo 16 �h�b�gROM�t�H���g����BDF�^���̃t�H���g���쐬���܂��B
echo ���p PEKE16R.BDF   �S�p PEKE16K.BDF
pause
echo ���p�t�@�C�����쐬���Ă��܂��B
mkbdf16r > PEKE16R.BDF

echo �S�p�t�@�C�����쐬���Ă��܂��E�E�E���΂炭���҂����������B

if "%1" == "-t" goto tiny
if "%1" == "-T" goto tiny
if "%1" == "/t" goto tiny
if "%1" == "/T" goto tiny

goto full

:tiny
echo ���ԃt�@�C����PEKE16K_.BDF�Ƃ��č쐬���܂��B
echo UNIX�}�V������sed�X�g���[���G�f�B�^���g���������K�v�Ƃ��܂��B

mkbdf16k -t > PEKE16K_.BDF

:full

mkbdf16k  > PEKE16K.BDF

echo �t�H���g�̍쐬���I�����܂����B