##Part 1. Установка ОС
---
1.	Установка Ubuntu 20.04 Server LTS без графического интерфейса.
	- Скачиваем и устанавливаем программу VirtualBox с сайта https://www.virtualbox.org/wiki/Downloads
	- Скачиваем и устанавливаем образ Ubuntu 20.04 Server LTS с официального сайта https://www.releases.ubuntu.com/20.04

```
Вывод команды cat /etc/issue для определения установленной версии Ubuntu
```
![./Screenshots/part1_ubuntu_version.png](./Screenshots/part1_ubuntu_version.png)

##Part 2. Создание пользователя
---
1.	Создание пользователя с добавлением в группу adm.

```
Вызов команды с созданием нового пользователя с добавлением в группу adm
```
![./Screenshots/part2.0_user_creation.png](./Screenshots/part2.0_user_creation.png)

```
Отображение созданного пользователя посредством вызова команды cat /etc/passwd
```
![./Screenshots/part2.1_show_navigato.png](./Screenshots/part2.1_show_navigato.png)

##Part 3. Настройка сети ОС
---
1.	Задание название машины вида user-1.

```
Смена названия машины и проверка смены названия машины до перезагрузки системы
```
![./Screenshots/part3.0_new_name_machine_user-1.png](./Screenshots/part3.0_new_name_machine_user-1.png)

```
Смена названия машины на navigato-1 и проверка смены названия машины до перезагрузки
```
![./Screenshots/part3.2_new_name_machine_navigato-1.png](./Screenshots/part3.2_new_name_machine_navigato-1.png)

```
 Проверка названия машины после перезагрузки
```
![./Screenshots/part3.3_new_name_machine_navigato-1.png](./Screenshots/part3.3_new_name_machine_navigato-1.png)

2.	Установка временной зоны, соответствующей текущему положению.

```
Вывод команды для установки временной зоны + проверка установки местного времени
```
![./Screenshots/part3.4_set_timezone.png](./Screenshots/part3.4_set_timezone.png)

3.	Вывод названия сетевых интерфейсов с помощью консольной команды
> lo (local loopback) используется для обращения компьютера к самому себе и имеет по умолчанию
```
Вывод 3-мя командами с разной глубиной информации о сетевых интерфейсах
```
![./Screenshots/part3.5name_interfaces.png](./Screenshots/part3.5name_interfaces.png)

4.	Получить ip адрес устройства от DHCP сервера

```
