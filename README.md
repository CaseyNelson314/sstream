# sstream

## ostream on Arduino

シリアル通信への出力を C++ 標準の出力挿入のように行うクラス

Arduino のシリアル通信ライブラリにそのような出力方法が存在しないため実装

## Usage

### 使用例

```cpp
void setup() {
	Serial.begin(115200); // シリアル通信開始

	std::sout << "example" << std::tab << 123 << std::endl;  // 出力> [example	123]

	std::sout << 123;
	std::sout << 456;
	std::sout << 789;
	std::sout << std::endl;  // 出力>123456789
}
```
> 標準の `cout` と異なり `endl` が呼び出された時点で出力される

### 自作クラスでの使用

> 自作クラス内で挿入演算子をオーバーロードすることで以下のようにインスタンスを挿入できる
```cpp
void setup() {
	Serial.begin(115200);  // シリアル通信開始
	Sample sample(1234);   // インスタンス変数作成
	std::sout << sample << std::endl;  // 出力> [1234]
}
```

> 例

```cpp
class Sample {
	const int menber_variable;
  public:
	Sample(int param): menber_variable(param) {}
	friend std::sstream& operator<<(std::sstream& ss, const Sample& input) /*noexcept*/ {  // ※ストリーム挿入は例外を投入しない
		ss << input.menber_variable;  // メンバ変数をストリーム挿入
		return ss;                    // 連続挿入を可能にするために必ず参照を返す
	}
}
```

## Note

### 内部構造

```cpp
String streambuf = "";

class sstream {
	template<class T>
	friend sstream& operator<<(sstream &sstrm, const T input) noexcept {
		streambuf += input;
		return sstrm;
	}
}
extern sstream sout;
```

### stream

> 挿入演算子の右辺値を挿入値として受け取る
>
> 全てのデータ型に対応させるため, メソッドをテンプレート化
>
> `String` 型をストリームバッファとし, 挿入演算子 `<<` が呼ばれるたびバッファに挿入する
>
> バッファ挿入は `String` クラスの `operator+=` によって行われるため `String` 型への変換は自動で行われる
>
> 参照型を返すので連続挿入が可能

### オプション挿入

> 標準の `endl` は改行挿入のため `const char endl = '\n'` としてもよかったが
>
> ~~`sout` 側から出力する方法がわからなかった~~ オプション挿入内で色々処理させたかったので, 関数とした
>
> 実際, 標準の `endl` は関数

> 関数を引数にとるために 挿入演算子を新たに作成
```cpp
friend sstream& operator<<(sstream &sstrm, void(*input)()) noexcept {  // 関数ポインタを引数にとる
	input();
	return sstrm;
}
```
