AccessGuard with ESP

معرفی پروژه

این پروژه یک سیستم کنترل دسترسی است که از برد ESP32، ماژول RFID RC522، نمایشگر OLED و صفحه‌کلید (Keypad) استفاده می‌کند. در این سیستم، کاربران می‌توانند با ارائه یک کارت RFID معتبر و وارد کردن رمز عبور صحیح، دسترسی داشته باشند. در صورت تطابق اطلاعات، چراغ سبز روشن شده و یک بوق تأیید پخش می‌شود. در غیر این صورت، چراغ قرمز روشن شده و یک بوق هشدار پخش خواهد شد.

قطعات مورد نیاز

برد ESP32 (جهت پردازش اطلاعات و کنترل ماژول‌ها)

ماژول RFID RC522 (جهت خواندن کارت‌های RFID)

نمایشگر OLED (برای نمایش وضعیت سیستم)

صفحه‌کلید (Keypad) (جهت ورود رمز عبور)

LED قرمز و سبز (جهت نمایش وضعیت دسترسی)

بازر (Buzzer) (برای اعلام وضعیت تأیید یا هشدار)

منبع تغذیه مناسب

نحوه کارکرد سیستم

خواندن کارت RFID: سیستم کارت را از طریق ماژول RC522 خوانده و شناسه آن را بررسی می‌کند.

وارد کردن رمز عبور: در صورت معتبر بودن کارت، از کاربر درخواست می‌شود که رمز عبور خود را از طریق Keypad وارد کند.

اعتبارسنجی اطلاعات: اگر کارت و رمز عبور هر دو معتبر باشند:

LED سبز روشن می‌شود.

بوق تأیید پخش می‌شود.

دسترسی مجاز خواهد بود.

خطا در ورود اطلاعات: اگر کارت نامعتبر باشد یا رمز عبور اشتباه وارد شود:

LED قرمز روشن می‌شود.

بوق هشدار فعال می‌شود.

دسترسی رد خواهد شد.

نحوه راه‌اندازی و اجرا

نصب کتابخانه‌های مورد نیاز:

MFRC522.h برای ماژول RFID

Wire.h و Adafruit_SSD1306.h برای OLED

Adafruit_GFX.h برای گرافیک نمایشگر OLED

Keypad.h برای صفحه‌کلید

اتصال سخت‌افزار:

RC522 به ESP32 متصل شود.

OLED به ESP32 متصل شود.

Keypad به پین‌های مناسب ESP32 وصل شود.

آپلود کد روی ESP32:

استفاده از Arduino IDE یا PlatformIO

تنظیم پین‌های ورودی و خروجی

آپلود کد و تست عملکرد

نحوه استفاده

کارت RFID خود را روی ماژول قرار دهید.

در صورت معتبر بودن، رمز عبور را از طریق Keypad وارد کنید.

نتیجه عملیات را روی نمایشگر OLED مشاهده کنید.

توسعه و بهبود

امکان افزودن حافظه برای ذخیره کارت‌ها و رمزهای عبور مجاز

اتصال به سرور برای ثبت لاگ‌های ورود و خروج

افزودن ارتباط بی‌سیم از طریق WiFi برای کنترل از راه دور

لایسنس

این پروژه تحت لایسنس MIT منتشر شده و استفاده از آن با ذکر منبع آزاد است.

