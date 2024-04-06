-- premake5.lua
workspace "Celestine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "CelestineApp"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "CelestineExternal.lua"
include "CelestineApp"