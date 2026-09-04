idf_component_register(
    SRCS "ride_on_dash.c"
        "../ui_engine/ui_engine.c"
        "../ui_engine/driver/display_driver.c"
        "../ui_engine/view/input.c"
        "../ui_engine/view/model.c"
        "../ui_engine/view/style.c"
        "../ui_engine/view/ui_screens.c"
        "../ui_engine/view/screen/home.c"
        "../ui_engine/view/screen/light.c"
        "../ui_engine/view/screen/splash.c"

        "../bridge/bridge.c"

        "../config/_color.c"

        "../system/_system.c"
        "../system/controller/led_controller.c"
        "../system/driver/led_driver.c"

    INCLUDE_DIRS "."
        "../ui_engine"
        "../ui_engine/driver"
        "../ui_engine/view"
        "../ui_engine/view/screen"

        "../bridge"

        "../config"

        "../system"
        "../system/controller"
        "../system/driver"
    )
