target_sources(sm PRIVATE
    "config.c"
    "glsl_shader.c"
    "main.c"
    "opengl.c"
    "sm_80.c"
    "sm_81.c"
    "sm_82.c"
    "sm_83.c"
    "sm_84.c"
    "sm_85.c"
    "sm_86.c"
    "sm_87.c"
    "sm_88.c"
    "sm_89.c"
    "sm_8b.c"
    "sm_8d.c"
    "sm_8f.c"
    "sm_90.c"
    "sm_91.c"
    "sm_92.c"
    "sm_93.c"
    "sm_94.c"
    "sm_9b.c"
    "sm_a0.c"
    "sm_a2.c"
    "sm_a3.c"
    "sm_a4.c"
    "sm_a5.c"
    "sm_a6.c"
    "sm_a7.c"
    "sm_a8.c"
    "sm_a9.c"
    "sm_aa.c"
    "sm_ad.c"
    "sm_b2.c"
    "sm_b3.c"
    "sm_b4.c"
    "sm_cpu_infra.c"
    "sm_rtl.c"
    "spc_player.c"
    "tracing.c"
    "util.c"

    "snes/apu.c"
    "snes/cart.c"
    "snes/cpu.c"
    "snes/dma.c"
    "snes/dsp.c"
    "snes/input.c"
    "snes/ppu.c"
    "snes/snes.c"
    "snes/snes_other.c"
    "snes/spc.c"
 "extra_features.h")

target_include_directories(sm PRIVATE "." "snes")

if (MSVC)
    target_include_directories(sm PRIVATE "platform/win32")
    target_sources(sm PRIVATE "platform/win32/volume_control.c")
endif()

if (NINTENDO_SWITCH)
    target_include_directories(sm PRIVATE "platform/switch/src")
    target_sources(sm PRIVATE "platform/switch/src/switch_impl.c")
endif()