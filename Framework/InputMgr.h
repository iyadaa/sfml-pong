#pragma once

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;
	std::list<sf::Keyboard::Key> positives; //1.f;
	std::list<sf::Keyboard::Key> negatives;

	float sensi = 100.f; //ũ�� ������ ����, ������ ������ ����
	float value = 0.f; //�ึ�� value��� ���� ��� �־ 
};

class InputMgr
{
private:
	//������ �����̳� �߰����� �ʴ� ���·� ���� 
	static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;
	static std::list<sf::Keyboard::Key> upKeys;

	static std::unordered_map<Axis, AxisInfo> axisInfoMap;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);

	static float GetAxisRaw(Axis axis);
	static float GetAxis(Axis axis);

	//�Լ� �߰�
	static bool GetMouseButtonDown(sf::Mouse::Button button);
	static bool GetMouseButtonUp(sf::Mouse::Button button);
	static bool GetMouseButton(sf::Mouse::Button button);

	static sf::Vector2i GetMousePosition();
};