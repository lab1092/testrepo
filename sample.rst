===========================================================
LibreOffice+JODConverterを使って、reSTからPDFを作ってみる。
===========================================================

   ..
      コメント行、反映されるかな？

LibreOffie経由でPDF作れるそうなので作ってみました。

ほとんど先人の知恵を少しばかり拝借した代物なんですが。

なお、Windowsで作業を行いました。

必要なもの
==========

とりあえず適当にダウンロードしておいてください。

   * java
   * LibreOffice
   * jodconverter
   * python
   * docutils


インストール
============

java
----

インストーラーを実行して、インストールを行います。

環境変数を設定します。インストールされたjavaに合わせてください。
(まあ、お決まりですけど)

   * JAVA_HOME

Python
-------

自身の環境ではPython 2.6.6が既にインストールされていますので、
それを使っています。多分2.7でもいいと思いますけれども。

必要ならインストーラーを実行して、インストールを行います。

   自身の環境では、インストールパスは C:\\Python26 でした。

この時点ですでに、パスに"C:\\Python26;C:\\Python26\\Scripts"が
追加されているはずですね?

Docutils
--------

PyPi( http://pypi.python.org/pypi ,読み:ぱいぴーあい)から

   Docutils

をダウンロードし、セットアップします。


LibreOffice
--------------

これもインストーラーの指示に従ってインストールします。

インストール先のディレクトリを確認しておいてください。

   "C:\Program Files\LibreOffice 3"

インストール後の準備
====================

上記が滞りなくダウンロード、セットアップされていることを
確認出来たら、以下を行います。

   * styles.odt のコピー
   * バッチファイルの作成(rst2odt.bat)
   * styles.odt の編集

本来はもっと厳密無出力用の設定を行わないといけないんでしょう
けれども、ページ設定をA4にしたものを簡単に用意しておきます。

styles.odt のコピー
-------------------

まずはstyles.odtをコピーしてきましょう。自分の環境では、以下
にありました。

   C:\\Python26\\Lib\\site-packages\\docutils-0.6-py2.6.egg\\docutils\\writers\odf_odt\\styles.odt


バッチファイルの作成(rst2odt.bat)
---------------------------------

バッチファイルを3つ作成します。いちいちタイプするのが面倒なので。

なお、記述の際にはファイルパス、ファイル名とも自分の環境に合わせて
適宜変更していただければいいと思います。

start.bat
~~~~~~~~~

LibreOfficeを「待ち受け」状態にしておきます。これにJODconverterからファイル変換の命令を出すわけです。

::

   set sofficeexe="C:\Program Files\LibreOffice 3\program\soffice.exe"
   %sofficeexe% -headless -accept="socket,port=8100;urp;" -nofirststartwizard


rst2odt.bat
~~~~~~~~~~~~

スタイルシートオプションに"styles.odt"を指定したものを作成しておきます。

   c:\python26\python.exe C:\Python26\Scripts\rst2odt.py --stylesheet=styles.odt sample.rst sample.odt

odt2pdf.bat
~~~~~~~~~~~~

JODconverterを実行するためのバッチファイルです。 start.batを実行してから、これを実行します。

::

   java -jar C:\usr\w32bin\jodconverter-2.2.2\lib\jodconverter-cli-2.2.2.jar sample.odt sample.pdf


styles.odt の編集
-----------------

コピーした styles.odt のページ設定とフォント設定を変更します。

   1. メニューから 書式 > ページ を選択します。
   2. [ページ]タブをクリックし、用紙の書式を"A4"に、余白を調整します。
   3. [OK]ボタンを押します。
   4. メニューから ツール > オプション を選びます。
   5. ツリーから、 LibreOffice Writer > 既定のフォント(西欧諸言語)
      を 選択します。
   6. 現在のドキュメントのみ にチェックを入れます。
   7. 画面右下の[標準]ボタンを押します。これでOSで使えるフォントが
      設定されます。
   8. 既定のフォント(アジア諸言語) も同様に設定します。自分はここ
      で使用フォントを メイリオ に設定しました。
   9. ファイルを保存します。

これが、書式を規定するファイルです。他にも見出し、など書式の設定
をしなくてはならないのですが、ここでは飛ばします。

それらを終えたら

   * rstファイルの用意(sample.rst)
   * rst2odt.bat の実行
   * start.bat の実行
   * odt2pdf.bat  の実行

注意点
======

start.bat で LibreOfficeを待ち受け状態にしていますが、変換が
終わったら、タスクマネージャから"soffice.exe"を終了させる必要が
あります。

自分の環境は…
==============

今回使用した環境ではJODConverterを追加で配置したので、
すべて最新バージョンというわけではありません。JODConverter自体も
最新の3.0-betaではないですしね。

   * Python 2.6.6
   * docutils 0.6
   * LibreOffice 3.3.1
   * JODConverter 2.2.2