idf_component_register(
    SRCS "main.c"

        "../common/bridge.c"
        "../common/colors.c"

        "../car_system/car_system.c"
        
        "../drivers/display_driver.c"
        "../drivers/led_driver.c"
        "../drivers/sound_driver.c"
        "../drivers/storage_driver.c"

        "../ui_engine/_lvgl.c"
        "../ui_engine/ui_engine.c"
        "../ui_engine/screen/home.c"
        "../ui_engine/screen/light.c"
        "../ui_engine/screen/splash.c"
        "../ui_engine/util/layout.c"
        "../ui_engine/widget/button_base.c"
        "../ui_engine/widget/color_picker.c"

    INCLUDE_DIRS "."
        "../common"

        "../car_system"

        "../drivers"

        "../ui_engine"
        "../ui_engine/util"
        "../ui_engine/screen"
        "../ui_engine/widget"

    REQUIRES esp_lcd esp_timer esp_driver_sdmmc esp_driver_i2s fatfs    
)
