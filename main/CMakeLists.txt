idf_component_register(
    SRCS "ride_on_dash.c"
        "../app/app.c"
        "../app/engine/engine.c"
        "../app/input/input.c"
        "../app/ui/screen/accessory/model_accessory.c"
        "../app/ui/screen/accessory/presenter_accessory.c"
        "../app/ui/screen/accessory/view_accessory.c"
        "../app/ui/screen/home/presenter_home.c"
        "../app/ui/screen/home/view_home.c"
        "../app/ui/style/style.c"
        "../app/ui/widget/color_picker/model_color_picker.c"
        "../app/ui/widget/color_picker/presenter_color_picker.c"
        "../app/ui/widget/color_picker/view_color_picker.c"

        "../bridge/bridge.c"

        "../config/_color.c"

        "../system/_system.c"
        "../system/controller/led_controller.c"
        "../system/driver/led_driver.c"

    INCLUDE_DIRS "."
        "../app"
        "../app/engine"
        "../app/ui/include"
        "../app/ui/screen/include"
        "../app/ui/screen/accessory/include"
        "../app/ui/screen/home/include"
        "../app/ui/style"
        "../app/ui/widget/include"
        "../app/ui/widget/color_picker/include"

        "../bridge"

        "../config"

        "../system"
        "../system/controller"
        "../system/driver"
    )
