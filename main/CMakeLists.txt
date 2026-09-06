idf_component_register(
    SRCS "main.c"

        "../common/bridge.c"
        "../common/_color.c"

        "../car_system/car_system.c"
        "../car_system/controller/led_controller.c"
        "../car_system/driver/led_driver.c"
        "../car_system/driver/sound_driver.c"
        "../car_system/driver/storage_driver.c"

        "../ui_engine/ui_engine.c"
        "../ui_engine/driver/display_driver.c"
        "../ui_engine/view/style.c"
        "../ui_engine/view/screen/home.c"
        "../ui_engine/view/screen/light.c"
        "../ui_engine/view/screen/splash.c"
        "../ui_engine/view/widget/button_base.c"
        "../ui_engine/view/widget/color_picker.c"

    INCLUDE_DIRS "."
        "../common"

        "../car_system"
        "../car_system/controller"
        "../car_system/driver"

        "../ui_engine"
        "../ui_engine/driver"
        "../ui_engine/view"
        "../ui_engine/view/screen"
        "../ui_engine/view/widget"

    REQUIRES esp_lcd esp_timer esp_driver_sdmmc esp_driver_i2s fatfs    
)
