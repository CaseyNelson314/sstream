# sstream

## iostream on Arduino

シリアル通信への出力挿入を C++ 標準の出力挿入のように行うクラス

Arduino のシリアル通信ライブラリにそのような出力方法が存在しないため実装

## Usage

```cpp
void setup(){

	Serial.begin(115200); // シリアル通信開始

	std::sout << "example" << tab << 123 << std::endl;  // 出力> [example	123]

	std::sout << 123;
	std::sout << 456;
	std::sout << 789;
	std::sout << std::endl;  // 出力>123456789

}
```

`std::cout` と異なり `std::endl` が呼び出された時点で出力される

## Note

```cpp
String streambuf = "";

class sstream {
	template<class T>
	friend sstream& operator<<(sstream &sstrm, T out) {
	streambuf += out;
	return sstrm;
	}
}
```

### sstream

> 挿入演算子の右辺値を挿入値として受け取る
>
> 全てのデータ型に対応させるため, メソッドをテンプレート化
>
> `String` 型をストリームバッファとし, 挿入演算子 `<<` が呼ばれるたびバッファに挿入する
>
> バッファー挿入は `String` クラスの `operator+=` によって行われるため `String` 型への変換は自動で行われる
>
> 参照型を返すので連続挿入が可能

### オプション挿入

> 標準の `endl` は改行挿入のため `const char endl = '\n'` としてもよかったが
>
> `sout` 側から出力する方法がわからなかったので,  関数とした

```cpp
friend sstream& operator<<(sstream &sstrm, void(*f)()) {
  f();
  return sstrm;
}
```

> 関数を引数にとるため, 挿入演算子を新たに作成
