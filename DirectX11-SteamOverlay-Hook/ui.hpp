#pragma once

#define  IMGUI_DEFINE_MATH_OPERATORS

#include <string>
#include <vector>
#include <functional>
#include "imgui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include "xorstr.hpp"

using namespace std;
using namespace ImGui;

#define to_vec4( r, g, b, a ) ImColor( r / 255.f, g / 255.f, b / 255.f, a )

class c_custom
{
public:
    float m_anim = 0.f;
    int m_rage_subtab = 0;
    vector < const char* > rage_subtabs = { "Player", "Weapon", "Quest", "Misc", "Settings" };
    void render_arrows_for_horizontal_bar(ImVec2 pos, float alpha, float width, float height);
    bool expand_button(const char* label, bool selected, float rounding = 0.f, ImDrawFlags flags = NULL);
    bool tab(const char* icon, const char* label, bool selected);
    bool sub_tab(const char* label, bool selected);
    void tab_area(const char* str_id, ImVec2 size, std::function < void() > content);
    void begin_child(const char* name, ImVec2 size);
    void end_child();
    int accent_color[4] = { 0, 90, 70, 255 };
    ImColor get_accent_color(float a = 1.f) { return to_vec4(accent_color[0], accent_color[1], accent_color[2], a); }
};

inline c_custom custom;
