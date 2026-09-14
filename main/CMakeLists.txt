idf_component_register(
    SRCS "main.c"

        "../src/_lvgl.c"
        "../src/car.c"

        "../src/common/colors.c"
        "../src/common/layout.c"

        "../src/drivers/display_driver.c"
        "../src/drivers/led_driver.c"
        "../src/drivers/sound_driver.c"
        "../src/drivers/storage_driver.c"

        "../src/screen/main_screen.c"

        "../src/screen/home/v_home.c"

        "../src/screen/light/v_light.c"
        "../src/screen/light/vm_light.c"

        "../src/widget/button/v_button.c"
        "../src/widget/button/vm_button.c"

        "../src/widget/color_picker/v_color_picker.c"
        "../src/widget/color_picker/vm_color_picker.c"

    INCLUDE_DIRS "."
        "../src"
        "../src/common/includes"
        "../src/drivers/includes"
        "../src/screen"
        "../src/screen/home/includes"
        "../src/screen/light/includes"
        "../src/system/includes"
        "../src/widget/button/includes"
        "../src/widget/color_picker/includes"

    REQUIRES esp_lcd esp_timer esp_driver_sdmmc esp_driver_i2s fatfs    
)
