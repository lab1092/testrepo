===========================================================
LibreOffice+JODConverter���g���āAreST����PDF������Ă݂�B
===========================================================

   ..
      �R�����g�s�A���f����邩�ȁH

LibreOffie�o�R��PDF���邻���Ȃ̂ō���Ă݂܂����B

�قƂ�ǐ�l�̒m�b�������΂���q�؂����㕨�Ȃ�ł����B

�Ȃ��AWindows�ō�Ƃ��s���܂����B

�K�v�Ȃ���
==========

�Ƃ肠�����K���Ƀ_�E�����[�h���Ă����Ă��������B

   * java
   * LibreOffice
   * jodconverter
   * python
   * docutils


�C���X�g�[��
============

java
----

�C���X�g�[���[�����s���āA�C���X�g�[�����s���܂��B

���ϐ���ݒ肵�܂��B�C���X�g�[�����ꂽjava�ɍ��킹�Ă��������B
(�܂��A�����܂�ł�����)

   * JAVA_HOME

Python
-------

���g�̊��ł�Python 2.6.6�����ɃC���X�g�[������Ă��܂��̂ŁA
������g���Ă��܂��B����2.7�ł������Ǝv���܂�����ǂ��B

�K�v�Ȃ�C���X�g�[���[�����s���āA�C���X�g�[�����s���܂��B

   ���g�̊��ł́A�C���X�g�[���p�X�� C:\\Python26 �ł����B

���̎��_�ł��łɁA�p�X��"C:\\Python26;C:\\Python26\\Scripts"��
�ǉ�����Ă���͂��ł���?

Docutils
--------

PyPi( http://pypi.python.org/pypi ,�ǂ�:�ς��ҁ[����)����

   Docutils

���_�E�����[�h���A�Z�b�g�A�b�v���܂��B


LibreOffice
--------------

������C���X�g�[���[�̎w���ɏ]���ăC���X�g�[�����܂��B

�C���X�g�[����̃f�B���N�g�����m�F���Ă����Ă��������B

   "C:\Program Files\LibreOffice 3"

�C���X�g�[����̏���
====================

��L���؂�Ȃ��_�E�����[�h�A�Z�b�g�A�b�v����Ă��邱�Ƃ�
�m�F�o������A�ȉ����s���܂��B

   * styles.odt �̃R�s�[
   * �o�b�`�t�@�C���̍쐬(rst2odt.bat)
   * styles.odt �̕ҏW

�{���͂����ƌ������o�͗p�̐ݒ���s��Ȃ��Ƃ����Ȃ���ł��傤
����ǂ��A�y�[�W�ݒ��A4�ɂ������̂��ȒP�ɗp�ӂ��Ă����܂��B

styles.odt �̃R�s�[
-------------------

�܂���styles.odt���R�s�[���Ă��܂��傤�B�����̊��ł́A�ȉ�
�ɂ���܂����B

   C:\\Python26\\Lib\\site-packages\\docutils-0.6-py2.6.egg\\docutils\\writers\odf_odt\\styles.odt


�o�b�`�t�@�C���̍쐬(rst2odt.bat)
---------------------------------

�o�b�`�t�@�C����3�쐬���܂��B���������^�C�v����̂��ʓ|�Ȃ̂ŁB

�Ȃ��A�L�q�̍ۂɂ̓t�@�C���p�X�A�t�@�C�����Ƃ������̊��ɍ��킹��
�K�X�ύX���Ă���������΂����Ǝv���܂��B

start.bat
~~~~~~~~~

LibreOffice���u�҂��󂯁v��Ԃɂ��Ă����܂��B�����JODconverter����t�@�C���ϊ��̖��߂��o���킯�ł��B

::

   set sofficeexe="C:\Program Files\LibreOffice 3\program\soffice.exe"
   %sofficeexe% -headless -accept="socket,port=8100;urp;" -nofirststartwizard


rst2odt.bat
~~~~~~~~~~~~

�X�^�C���V�[�g�I�v�V������"styles.odt"���w�肵�����̂��쐬���Ă����܂��B

   c:\python26\python.exe C:\Python26\Scripts\rst2odt.py --stylesheet=styles.odt sample.rst sample.odt

odt2pdf.bat
~~~~~~~~~~~~

JODconverter�����s���邽�߂̃o�b�`�t�@�C���ł��B start.bat�����s���Ă���A��������s���܂��B

::

   java -jar C:\usr\w32bin\jodconverter-2.2.2\lib\jodconverter-cli-2.2.2.jar sample.odt sample.pdf


styles.odt �̕ҏW
-----------------

�R�s�[���� styles.odt �̃y�[�W�ݒ�ƃt�H���g�ݒ��ύX���܂��B

   1. ���j���[���� ���� > �y�[�W ��I�����܂��B
   2. [�y�[�W]�^�u���N���b�N���A�p���̏�����"A4"�ɁA�]���𒲐����܂��B
   3. [OK]�{�^���������܂��B
   4. ���j���[���� �c�[�� > �I�v�V���� ��I�т܂��B
   5. �c���[����A LibreOffice Writer > ����̃t�H���g(����������)
      �� �I�����܂��B
   6. ���݂̃h�L�������g�̂� �Ƀ`�F�b�N�����܂��B
   7. ��ʉE����[�W��]�{�^���������܂��B�����OS�Ŏg����t�H���g��
      �ݒ肳��܂��B
   8. ����̃t�H���g(�A�W�A������) �����l�ɐݒ肵�܂��B�����͂���
      �Ŏg�p�t�H���g�� ���C���I �ɐݒ肵�܂����B
   9. �t�@�C����ۑ����܂��B

���ꂪ�A�������K�肷��t�@�C���ł��B���ɂ����o���A�ȂǏ����̐ݒ�
�����Ȃ��Ă͂Ȃ�Ȃ��̂ł����A�����ł͔�΂��܂��B

�������I������

   * rst�t�@�C���̗p��(sample.rst)
   * rst2odt.bat �̎��s
   * start.bat �̎��s
   * odt2pdf.bat  �̎��s

���ӓ_
======

start.bat �� LibreOffice��҂��󂯏�Ԃɂ��Ă��܂����A�ϊ���
�I�������A�^�X�N�}�l�[�W������"soffice.exe"���I��������K�v��
����܂��B

�����̊��́c
==============

����g�p�������ł�JODConverter��ǉ��Ŕz�u�����̂ŁA
���ׂčŐV�o�[�W�����Ƃ����킯�ł͂���܂���BJODConverter���̂�
�ŐV��3.0-beta�ł͂Ȃ��ł����ˁB

   * Python 2.6.6
   * docutils 0.6
   * LibreOffice 3.3.1
   * JODConverter 2.2.2