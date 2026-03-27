# Otto Robot GIF Emoji Component

ESP-IDF component that provides 6 embedded Otto robot GIF emoji resources for LVGL v9.

## Content

- **Embedded GIF resources**: 6 animated GIF表情 compiled into C arrays
  - `staticstate` - 静态状态/中性表情
  - `sad` - 悲伤表情
  - `happy` - 开心表情
  - `scare` - 惊吓/惊讶表情
  - `buxue` - 不学/困惑表情
  - `anger` - 愤怒表情
- **C API**: Get resources by name or index
- **LVGL v9 compatible**: Uses `lv_image_dsc_t` and `LV_IMAGE_DECLARE`

## Requirements

- ESP-IDF
- LVGL >= 9.0

## Usage

Add to your project's `idf_component.yml`:

```yaml
dependencies:
  txp666/otto-emoji-gif-component: "^1.1.0"
```

In code:

```c
#include "otto_emoji_gif.h"
#include "lvgl.h"

// 方法1: 直接使用声明的GIF资源
lv_obj_t* gif = lv_gif_create(parent);
lv_gif_set_src(gif, &happy);  // 设置开心表情

// 方法2: 通过索引获取 (0-5)
const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_index(2);  // happy
if (gif_data) {
    lv_gif_set_src(gif, gif_data);
}

// 方法3: 通过名称获取
const lv_image_dsc_t* gif_data = otto_emoji_gif_get_by_name("anger");
if (gif_data) {
    lv_gif_set_src(gif, gif_data);
}

// 获取信息
printf("Version: %s\n", otto_emoji_gif_get_version());
printf("Count: %d\n", otto_emoji_gif_get_count());
const char* name = otto_emoji_gif_get_name(0);  // "staticstate"
```

### 索引顺序

| 索引 | 名称 | 描述 |
|------|------|------|
| 0 | staticstate | 静态状态/中性表情 |
| 1 | sad | 悲伤表情 |
| 2 | happy | 开心表情 |
| 3 | scare | 惊吓/惊讶表情 |
| 4 | buxue | 不学/困惑表情 |
| 5 | anger | 愤怒表情 |

## Layout

```
otto-emoji-gif-component/
├── idf_component.yml
├── CMakeLists.txt
├── include/
│   └── otto_emoji_gif.h      # 公共API头文件
└── src/
    ├── otto_emoji_gif.c      # 基本信息
    ├── otto_emoji_gif_utils.c # 工具函数
    ├── staticstate.c         # 静态状态GIF数组
    ├── sad.c                 # 悲伤表情GIF数组
    ├── happy.c               # 开心表情GIF数组
    ├── scare.c               # 惊吓表情GIF数组
    ├── buxue.c               # 不学表情GIF数组
    └── anger.c               # 愤怒表情GIF数组
```

## License

MIT
