idf_component_register(
    SRCS "ride_on_dash.c"
        "../app/app.c"
        "../app/engine/engine.c"
        "../app/ui/input/input.c"
        "../app/ui/model/model.c"
        "../app/ui/ui_screens.c"
        "../app/ui/style/style.c"
        "../app/ui/screen/home/home.c"
        "../app/ui/screen/light/light.c"
        "../app/ui/screen/splash/splash.c"

        "../bridge/bridge.c"

        "../config/_color.c"

        "../system/_system.c"
        "../system/controller/led_controller.c"
        "../system/driver/led_driver.c"

    INCLUDE_DIRS "."
        "../app"
        "../app/engine"
        "../app/ui"
        "../app/ui/input"
        "../app/ui/model"
        "../app/ui/style"
        "../app/ui/screen/home"
        "../app/ui/screen/light"
        "../app/ui/screen/splash"

        "../bridge"

        "../config"

        "../system"
        "../system/controller"
        "../system/driver"
    )
