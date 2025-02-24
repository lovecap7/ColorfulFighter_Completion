#pragma once
#include <map>
#include <string>
#include <vector>
#include <list>

class Input
{
	/*/// <summary>
	/// シングルトン
	/// </summary>
private:
	Input() = default;
	~Input();
	Input(const Input&) = delete;
	Input& operator = (const Input&) = delete;
	Input(Input&&) = delete;
	Input& operator = (Input&&) = delete;*/

	//キーの方向記録
	void DirInfoSave();

public:
	/*static Input& GetInstance()
	{
		static Input instance;
		return instance;
	}*/

	/// <summary>
	/// スティックの傾きを保持する構造体
	/// </summary>
	struct StickInfo
	{
		StickInfo()
		{
			leftStickX = 0;
			leftStickY = 0;
			rightStickX = 0;
			rightStickY = 0;
		}
		int leftStickX;
		int leftStickY;
		int rightStickX;
		int rightStickY;
	};

	struct TriggerInfo
	{
		TriggerInfo()
		{
			left = 0;
			right = 0;
		}
		int left;
		int right;
	};
	~Input();
	/// <summary>
	/// キーの情報を更新する
	/// </summary>
	void Init();

	/// <summary>
	/// 扱うパッドのナンバー
	/// </summary>
	/// <param name="padIndex"></param>
	void PadInit(int padIndex);

	/// <summary>
	/// 入力情報を更新する
	/// </summary>
	void Update();

	/// <summary>
	/// 入力情報を受け付けないようにする
	/// </summary>
	void StopUpdate();

	/// <summary>
	/// キー押したかどうか
	/// </summary>
	/// <param name="keyName">判定したいキー</param>
	// <returns>押したかどうか</returns>
	bool IsPress(const std::string& action)const;


	/// <summary>
	/// キーを押された瞬間を取得する
	/// </summary>
	/// <param name="keyName">判定したいキー</param>
	/// <returns>押された瞬間のみtrue</returns>
	bool IsTrigger(const std::string& action)const;

	/// <summary>
	/// キーを離した瞬間を取得する
	/// </summary>
	/// <param name="keyName">判定したいキー</param>
	/// <returns>離された瞬間のみtrue</returns>
	bool IsRelease(const std::string& action)const;

	/// <summary>
	/// スティックの傾きを取得する
	/// </summary>
	/// <returns>スティックがどれだけ倒れているか</returns>
	StickInfo GetStickInfo() { return m_stickInfo; }

	/// <summary>
	/// トリガーの押し込み具合を取得する
	/// </summary>
	/// <returns>トリガーがどのくらい押し込まれているか</returns>
	TriggerInfo GetTriggerInfo() { return m_triggerInfo; }

	/// <summary>
	/// トリガーボタンを押しているかどうかを返す(押し込みの強さ可変)
	/// </summary>
	/// <param name="right">右側のボタンを取得したいならtrue</param>
	/// <param name="power">どのくらい押し込まれていたらtrueとするか(最大255,最小0)</param>
	/// <returns></returns>
	bool IsPushTrigger(bool right, int power);

	/// <summary>
	/// トリガーボタンを押しているかどうかを返す(押し込みの強さ固定)
	/// </summary>
	/// <param name="right"></param>
	/// <returns></returns>
	bool IsPushTrigger(bool right);

	

	/// <summary>
	/// コマンドをチェックする
	/// </summary>
	bool CheckDirCommand(std::string command);

	//タメコマンド
	bool CheckKeepCommand(std::string command);
	
private:
	/// <summary>
	/// 入力の種類
	/// </summary>
	enum class InputType
	{
		kKeyboard,
		kPad,
		kMouse
	};
	struct InputMapInfo
	{
		InputType type;
		int buttonID;
	};

	std::map<std::string, std::vector<InputMapInfo>> m_inputActionMap;

	//現在のフレームの入力
	std::map<std::string, bool>m_currentInput;
	//1フレーム前の入力
	std::map<std::string, bool>m_lastInput;

	StickInfo m_stickInfo = StickInfo();

	TriggerInfo m_triggerInfo = TriggerInfo();
	//スティックの方向
	enum class StickDir
	{
		Command,	//テンキー表示したいから0を適当に用意してみた
		LeftDown,	//1
		Down,		//2
		RightDown,	//3
		Left,		//4
		Neutral,	//5
		Right,		//6
		LeftUp,		//7
		Up,			//8
		RightUp,	//9
	};
	//スティックの方向の情報を持つ構造体
	struct StickDirInfo
	{
		StickDir dir;	//スティックの方向
		int frame;		//ある方向にスティックが入れられている間のフレーム
	};
	//StickDirInfo構造体をlistで持つ
	//方向の情報をこれに入れていく
	std::list<StickDirInfo> m_stickDirInfo;

	//コマンドリスト
	std::map < std::string, std::vector< StickDir>> m_commandList;

	//PADのIndex
	int m_padIndex;

};


