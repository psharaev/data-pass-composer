# Composer

Представляет собой класс для распределения данных

**Функции**

| Имя                               | Описание                                                     |
| --------------------------------- | ------------------------------------------------------------ |
| [Parse](#Parse) | Обрабатывает полученные данные |
| [AddBox](#AddBox)                 | Добавляет экземпляр [ComposerBox](#ComposerBox)              |
| [AddBoxForcibly](#AddBoxForcibly) | Добавляет экземпляр, заменяя старый [ComposerBox](#ComposerBox) |
| RemoveBox                         | Удаляет [ComposerBox](#ComposerBox)                                                  |

## Parse



## AddBox

```cpp
ComposerBox MyDevice;
Composer.AddBox(MyDevice);
```

```csharp
ComposerBox MyDevice;
Composer.AddBox(MyDevice);
```

```java
ComposerBox MyDevice;
Composer.AddBox(MyDevice);
```

**Возвращает**

`bool` - Удалось ли добавить (true - всё отлично; false - не получилось)

**Параметры**

| Параметр | Тип                         | Описание                                     |
| -------- | --------------------------- | -------------------------------------------- |
| box      | [ComposerBox](#ComposerBox) | Экземпляр класса [ComposerBox](#ComposerBox) |
| box_id   | [box_t](#Box_t)             | Идентификатор этого бокса                    |

## AddBoxForcibly