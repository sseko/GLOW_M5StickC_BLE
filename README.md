# GLOW_M5StickC_BLE
## M5StickCを使ってGLOWをコントロールする
##### プログラムの内容
M5StickCからGLOWを直接コントロールできます。

以下のように設定します。
- function -- ファンクション
- group -- GLOWのグループID
- id -- GLOWのデバイスID
- command -- コマンド

<pre>
uint32_t function;
uint32_t group;
uint32_t id;
uint32_t command;
sendGlowData(function,group,id,command);
</pre>

##### GLOWとは
GLOWは Yume Cloud 社が開発したユニークなLEDキューブです。

４つの高輝度カラーLEDを様々な光パターンで光らせることができるキューブ型デバイスです。

以下の特徴を持っています。

- 7つのグルーピングが可能
- １つのグループに1023個のデバイスIDを登録可能
- トータル７千１６１個のキューブを同時にコントロールできる
- ４つの高輝度カラーLEDを使って様々な光パターンを表現できる
- デバイスID、デバイスグループ、光パターンのすべてがプログラム可能
- 特に７千個以上のデバイスを同時にプログラムでコントロールできるデバイスは非常にユニークです。

これを使って大きなイベントを盛り上げたりするなど、使い方はアイディア次第です。
