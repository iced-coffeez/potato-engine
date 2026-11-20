#pragma once

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "potatoNewton.hpp"

enum class ObjectPreset {
	CheckeredCube,
	WhiteSphere,
	Potato,
	None
};

enum class ObjectType {
	Mesh,
	Billboard
};

enum class ElementType {
	Rect,
	Text,
	LinkedText,
	Unused
};

typedef struct WindowElement {
	WindowElement* parent = nullptr;

	Vector2 scale = { 1.0f, 1.0f };
	Vector2 pos = { 0.0f, 0.0f };
	
	ElementType eletype = ElementType::Unused;

} WindowElement;

typedef struct WindowSector {
	std::vector<WindowElement> elements;
	Vector2 pos = { 0.0f, 0.0f };
} WindowSector;

typedef struct Object {
	ObjectPreset preset = ObjectPreset::None;

	Mesh mesh = { 0 };
	Vector3 position = { 0.0f };
	Vector3 rotation = { 0.0f };
	Vector3 scale = { 1.0f, 1.0f, 1.0f };
	float billboardScale = 3.0f;

	Texture2D texture = { 0 };
	Texture2D normal = { 0 };
	bool textureRepeat = false;
	bool billboard = false;
	bool collides = true;
	float textureRepeatAmount = 1.0f;
} Object;

typedef struct InitializedObject {
	ObjectType type;
	
	Object *originalObjectToReadPropertiesFromIncaseTheyChange = nullptr;

	CollisionBox collisionBox;
	bool inactive = true;
	Matrix transform;
	Texture2D BillboardTexture = { 0 };
	Material material;
	Mesh *mesh;
	Vector3 scale = { 1.0f };
	float BillboardScale = 3.0f;
} InitializedObject;

void init_obj();

void add_object(Object *object);
void remove_object(Object *object);

void add_window(WindowSector *window);

void render_objects(Camera3D *camera);

void make_windows_work();

void unload_all_objects();
