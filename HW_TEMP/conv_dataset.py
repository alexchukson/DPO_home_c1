import pandas as pd
from datetime import datetime

# Предполагаем, что файл с данными называется 'india_climate.csv'
# Если имя другое, просто замените его в строке ниже.
INPUT_FILE = 'HW_TEMP\india_2000_2024_daily_weather.csv'
OUTPUT_FILE = 'HW_TEMP\india_2000_2024_daily_weather.txt'

try:
    # 1. Загружаем датасет
    print(f"Загрузка файла {INPUT_FILE}...")
    df = pd.read_csv(INPUT_FILE)
    
    # Убеждаемся, что колонка с датой распознана правильно
    df['date'] = pd.to_datetime(df['date'])
    
    print(f"Найдено {len(df)} записей. Начинаю обработку...")
    
    # 2. Открываем файл для записи результата
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
        for index, row in df.iterrows():
            # Извлекаем компоненты даты
            year = row['date'].year
            month = row['date'].month
            day = row['date'].day
            
            # Берем температуру. Можно заменить на temperature_2m_min, если нужно.
            # Округляем до целого, как в вашем ТЗ.
            temp_celsius = round(row['temperature_2m_max'])
            
            # Формируем строку в точности по вашему шаблону.
            # hh=12, mm=00, так как в датасете нет почасовых данных.
            output_line = (f"{year:04d} {month:02d} {day:02d} "
                           f"12 00{temp_celsius:3d}\n")
            
            f.write(output_line)
            
            # Небольшой индикатор прогресса для больших файлов
            if (index + 1) % 10000 == 0:
                print(f"  Обработано {index + 1} записей...")

    print(f"\nГотово! Результат сохранен в файл: {OUTPUT_FILE}")

except FileNotFoundError:
    print(f"Ошибка: Файл '{INPUT_FILE}' не найден.")
    print("Убедитесь, что вы скачали датасет и указали правильное имя файла.")
except Exception as e:
    print(f"Произошла ошибка: {e}")