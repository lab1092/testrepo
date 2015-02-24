echo off

echo MKBDF68k ROMフォント to BDFフォント作成バッチファイル
echo _
echo 16 ドットROMフォントからBDF型式のフォントを作成します。
echo 半角 PEKE16R.BDF   全角 PEKE16K.BDF
pause
echo 半角ファイルを作成しています。
mkbdf16r > PEKE16R.BDF

echo 全角ファイルを作成しています・・・しばらくお待ちください。

if "%1" == "-t" goto tiny
if "%1" == "-T" goto tiny
if "%1" == "/t" goto tiny
if "%1" == "/T" goto tiny

goto full

:tiny
echo 中間ファイルをPEKE16K_.BDFとして作成します。
echo UNIXマシン側でsedストリームエディタを使った操作を必要とします。

mkbdf16k -t > PEKE16K_.BDF

:full

mkbdf16k  > PEKE16K.BDF

echo フォントの作成が終了しました。
