idf_component_register(
    SRCS "ride_on_dash.c"
        "../ui_engine/ui_engine.c"
        "../ui_engine/driver/display_driver.c"
        "../ui_engine/view/style.c"
        "../ui_engine/view/screen/home.c"
        "../ui_engine/view/screen/light.c"
        "../ui_engine/view/screen/splash.c"
        "../ui_engine/view/widget/button_base.c"
        "../ui_engine/view/widget/color_picker.c"

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
        "../ui_engine/view/widget"

        "../bridge"

        "../config"

        "../system"
        "../system/controller"
        "../system/driver"
    )
