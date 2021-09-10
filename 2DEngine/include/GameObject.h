#ifndef WITZ_ENGINE_GAME_OBJECT_H
#define WITZ_ENGINE_GAME_OBJECT_H

namespace WitzEngineObjects
{
	class GameObject
	{
	public:
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void dispose() = 0;

	protected:
		GameObject() = default;
		virtual ~GameObject() = default;
	};
}

#endif
