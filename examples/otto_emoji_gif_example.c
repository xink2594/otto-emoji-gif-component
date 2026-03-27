/**
 * @file otto_emoji_gif_example.c
 * @brief Otto GIF表情组件使用示例
 *
 * 本示例展示如何使用otto_emoji_gif_component在LVGL中显示动态表情
 */

#include "otto_emoji_gif.h"
#include "lvgl.h"

/**
 * @brief 示例1: 直接使用声明的GIF资源
 */
void example_1_direct_usage(lv_obj_t* parent) {
    // 创建GIF对象
    lv_obj_t* gif = lv_gif_create(parent);

    // 直接使用预声明的GIF资源
    lv_gif_set_src(gif, &happy);  // 显示开心表情

    // 居中显示
    lv_obj_center(gif);

    // 设置大小 (GIF原始大小为240x240)
    lv_obj_set_size(gif, 240, 240);
}

/**
 * @brief 示例2: 通过索引获取GIF资源
 */
void example_2_get_by_index(lv_obj_t* parent) {
    // 创建GIF对象
    lv_obj_t* gif = lv_gif_create(parent);

    // 通过索引获取GIF资源 (0-5)
    const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_index(2);  // happy

    if (gif_data) {
        lv_gif_set_src(gif, gif_data);
        lv_obj_center(gif);
        lv_obj_set_size(gif, 240, 240);
    }
}

/**
 * @brief 示例3: 通过名称获取GIF资源
 */
void example_3_get_by_name(lv_obj_t* parent) {
    // 创建GIF对象
    lv_obj_t* gif = lv_gif_create(parent);

    // 通过名称获取GIF资源
    const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_name("anger");

    if (gif_data) {
        lv_gif_set_src(gif, gif_data);
        lv_obj_center(gif);
        lv_obj_set_size(gif, 240, 240);
    }
}

/**
 * @brief 示例4: 遍历所有表情并显示
 */
void example_4_show_all_emotions(lv_obj_t* parent) {
    printf("Otto Emoji GIF Component Demo\n");
    printf("Version: %s\n", otto_emoji_gif_get_version());
    printf("Total emotions: %d\n", otto_emoji_gif_get_count());
    printf("\n");

    // 遍历所有表情
    for (int i = 0; i < otto_emoji_gif_get_count(); i++) {
        const char* name = otto_emoji_gif_get_name(i);
        const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_index(i);

        if (name && gif_data) {
            printf("[%d] %s - size: %dx%d, data_size: %d bytes\n",
                   i, name, gif_data->header.w, gif_data->header.h, gif_data->data_size);
        }
    }

    // 在屏幕上显示一个表情作为示例
    lv_obj_t* gif = lv_gif_create(parent);
    lv_gif_set_src(gif, otto_emoji_gif_get_by_index(2));  // happy
    lv_obj_center(gif);
    lv_obj_set_size(gif, 240, 240);
}

/**
 * @brief 示例5: 创建表情切换按钮
 */
void example_5_emotion_switcher(lv_obj_t* parent) {
    static int current_index = 0;
    static lv_obj_t* gif = NULL;

    // 创建GIF对象
    gif = lv_gif_create(parent);
    lv_gif_set_src(gif, otto_emoji_gif_get_by_index(0));
    lv_obj_center(gif);
    lv_obj_set_size(gif, 240, 240);

    // 创建切换按钮
    lv_obj_t* btn = lv_button_create(parent);
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_t* label = lv_label_create(btn);
    lv_label_set_text(label, "Next");
    lv_obj_center(label);

    // 按钮点击事件
    lv_obj_add_event_cb(btn, [](lv_event_t* e) {
        // 切换到下一个表情
        current_index = (current_index + 1) % otto_emoji_gif_get_count();
        const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_index(current_index);

        if (gif_data) {
            lv_gif_set_src(gif, gif_data);
            printf("Switched to: %s\n", otto_emoji_gif_get_name(current_index));
        }
    }, LV_EVENT_CLICKED, NULL);
}

/**
 * @brief 主示例函数 - 在应用中调用
 */
void otto_emoji_gif_demo(lv_obj_t* screen) {
    // 选择一个示例运行
    example_1_direct_usage(screen);
    // 或者使用其他示例:
    // example_2_get_by_index(screen);
    // example_3_get_by_name(screen);
    // example_4_show_all_emotions(screen);
    // example_5_emotion_switcher(screen);
}

/* 使用说明:
 *
 * 1. 在项目中添加依赖 (idf_component.yml):
 *    dependencies:
 *      txp666/otto-emoji-gif-component: "^1.1.0"
 *
 * 2. 包含头文件:
 *    #include "otto_emoji_gif.h"
 *
 * 3. 创建GIF对象并设置资源:
 *    lv_obj_t* gif = lv_gif_create(parent);
 *    lv_gif_set_src(gif, &happy);  // 直接使用
 *
 * 4. 或者通过API获取:
 *    const lv_image_dsc_t* data = otto_emoji_gif_get_by_name("happy");
 *    lv_gif_set_src(gif, data);
 *
 * 注意事项:
 * - 所有GIF资源都是嵌入式的,不需要从文件系统加载
 * - GIF原始大小为240x240像素
 * - 需要LVGL v9和lv_gif库支持
 * - 表情索引范围: 0-5
 */
