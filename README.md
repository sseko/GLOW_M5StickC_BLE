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
