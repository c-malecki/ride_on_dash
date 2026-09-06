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
        "../ui_engine/view/screen/layout.c"
        "../ui_engine/view/screen/home.c"
        "../ui_engine/view/screen/light.c"
        "../ui_engine/view/screen/splash.c"
        "../ui_engine/view/widget/button_base.c"
        "../ui_engine/view/widget/color_picker.c"

    INCLUDE_DIRS "."
        "../common"

        "../car_system"

        "../drivers"

        "../ui_engine"
        "../ui_engine/view"
        "../ui_engine/view/screen"
        "../ui_engine/view/widget"

    REQUIRES esp_lcd esp_timer esp_driver_sdmmc esp_driver_i2s fatfs    
)
