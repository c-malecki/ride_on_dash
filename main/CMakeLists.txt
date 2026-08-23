idf_component_register(
    SRCS "ride_on_dash.c"
        "../app/app.c"
        "../drivers/led.c"
    INCLUDE_DIRS "."
        "../app"
        "../drivers"
    )
