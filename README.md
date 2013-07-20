lua_sample3
===========

# DESCRIPTION

Lua-C言語間で配列をやり取りするサンプル

# Luaのインストール

# LuaのC言語組み込み用ライブラリの取得

http://luabinaries.sourceforge.net/download.html
* 今回lua-5.2.1_MacOS107_lib.tar.gz をダウンロードして解凍

# ファイル構成

    .
    ├── Makefile
    ├── README.md
    ├── array.c
    ├── double.lua
    ├── luadebug.c
    └── luadebug.h

※lua用のライブラリは前述した圧縮ファイルをダウンロードして
  解凍したもののincludeディレクトリをコピーしてくる
