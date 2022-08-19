## Part 1. Установка ОС
---
	1.	Установка Ubuntu 20.04 Server LTS без графического интерфейса.
		- Скачиваем и устанавливаем программу VirtualBox с сайта https://www.virtualbox.org/wiki/Downloads
		- Скачиваем и устанавливаем образ Ubuntu 20.04 Server LTS с официального сайта https://www.releases.ubuntu.com/20.04

		`Вывод команды cat /etc/issue для определения установленной версии Ubuntu`
		![./Screenshots/part1_ubuntu_version.png](./Screenshots/part1_ubuntu_version.png)

## Part 2. Создание пользователя
---
	1.	Создание пользователя с добавлением в группу adm.

		`Вызов команды с созданием нового пользователя`
		![./Screenshots/part2.0_user_creation.png](./Screenshots/part2.0_user_creation.png)

		`Добавление пользователяя в группу adm`
		![./Screenshots/part2.4_add_adm.png](./Screenshots/part2.4_add_adm.png)

		`Отображение созданного пользователя посредством вызова команды cat /etc/passwd`
		![./Screenshots/part2.1_show_navigato.png](./Screenshots/part2.1_show_navigato.png)

## Part 3. Настройка сети ОС
---
	1.	Задание название машины вида user-1.

		`Смена названия машины и проверка смены названия машины до перезагрузки системы`
		![./Screenshots/part3.0_new_name_machine_user-1.png](./Screenshots/part3.0_new_name_machine_user-1.png)

		`Смена названия машины на navigato-1 и проверка смены названия машины до перезагрузки`
		![./Screenshots/part3.2_new_name_machine_navigato-1.png](./Screenshots/part3.2_new_name_machine_navigato-1.png)

		`Проверка названия машины после перезагрузки`
		![./Screenshots/part3.3_new_name_machine_navigato-1.png](./Screenshots/part3.3_new_name_machine_navigato-1.png)

	2.	Установка временной зоны, соответствующей текущему положению.

		`Вывод команды для установки временной зоны + проверка установки местного времени`
		![./Screenshots/part3.4_set_timezone.png](./Screenshots/part3.4_set_timezone.png)

	3.	Вывод названия сетевых интерфейсов с помощью консольной команды

		`Вывод 3-мя командами с разной глубиной информации о сетевых интерфейсах`
		![./Screenshots/part3.5name_interfaces.png](./Screenshots/part3.5name_interfaces.png)

		> lo (local loopback) интерфейс обратной петли используется для обращения компьютера к самому себе и имеет по
		> умолчанию ip-адрес 127.0.0.1  и необходим для нормальной работы системы

	4.	Получить ip адрес устройства от DHCP сервера с помощью консольной команды `hostname -I`

		![./Screenshots/part3.6_ip_DHCP.png](./Screenshots/part3.6_ip_DHCP.png)

		> DHCP (Dynamic Host Configuration Protocol - протокол динамической настройки узла) - прикладной протокол, 
		> позволяющий сетевым устройствам автоматически получать ip-адрес и другие параметры, необходимые для работы в сети TCP/IP.

	5.	Определить и вывести на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес по умолчанию (gw).

		![./Screenshots/part3.7_ip_out.png](./Screenshots/part3.7_ip_out.png)

	6.	Задать статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns 
		(использовать публичный DNS серверы, например 1.1.1.1 или 8.8.8.8).
		`Настройки полученные от DHCP сервера`
		![./Screenshots/part3.9.1_before.png](./Screenshots/part3.9.1_before.png)

		`Вносим изменения в yaml файл`
		![./Screenshots/part3.9.2_after.png](./Screenshots/part3.9.2_after.png)

		`Применяем и подтверждаем изменения`
		![./Screenshots/part3.9.3_apply.png](./Screenshots/part3.9.3_apply.png)

	7. Перезагружаем виртуальную машину. Убедиться, что статичные сетевые настройки (p, gw, dns) соответствуют заданным в предыдущем пункте
		![./Screenshots/part3.9.4_after_reboot.png](./Screenshots/part3.9.4_after_reboot.png)

		Успешно пропинговать удаленные хосты 1.1.1.1 и ya.ru и вставить в отчёт скрин с выводом команды. В выводе команды должна быть фраза "0% packet loss".

		`Пингуем удаленные хосты 1.1.1.1 и ya.ru`
		![./Screenshots/part3.9_ping.png](./Screenshots/part3.9_ping.png)

## Part 4. Обновление ОС
---
	1.	Обновить ситемные пакеты до последней на момент выполнения задания версии.
		- После обновления системных пакетов, если ввести команду обновления повторно, должно появится сообщение, что обновления отсутствуют.
		-Вставьте скриншот с этим сообщенеи в отчет.

		`Устанавливаем обновления командой sudo apt upgrade; показывается количество обновлений, после подтверждаем начало установки`
		![./Screenshots/part4.png](./Screenshots/part4.png)

		`Окончание установки обновлений`
		![./Screenshots/part4.1.png](./Screenshots/part4.1.png)

		`Проверка на отсутствие необходимости установить обновления`
		![./Screenshots/part4.2.png](./Screenshots/part4.2.png)

## Part 5. Использование команды sudo
---
	> Команда sudo (substitute user and do, подменить пользователя и выполнить) позволяет строго определенным пользователям выполнять 
	  указанные программы с административными привилегиями без ввода пароля суперпользователя root.

	1.	Выполнение программы от имени пользователя, созданного в Part 2. Команда `sudo -u navigato whoami`
		![./Screenshots/part5.png](./Screenshots/part5.png)

## Part 6. Установка и настройка службы времени
---

	1. Вывод команды `timedatectl show` содержит `NTPSynchronized=yes`
		![./Screenshots/part6_timedatectl_show.png](./Screenshots/part6_timedatectl_show.png)

## Part 7. Установка и использование текстовых редакторов
---

	1.	Установка текстовых редакторов:
		```
		sudo apt install vim
		sudo apt install nano
		sudo apt install mcedit
		```

	2.	Создание файла с сохранением изменений в 3-х редакторах
		- Для VIM создание файла командой `vim test_vim.txt`. Чобы начать редактировать файл жмем `i`. 
		  Для выхода из режима печати нажимаем `Esc`, далее вводим `:wq` и нажимаем на `Enter`.
		- Для Nano создание файла командой `nano test_nano.txt`. Для выхода с сохранением жмем `ctrl + x` и нажимаем `y`.
		- Для Mcedit создание файла командой `mcedit test_mcedit.txt`. Для сохранения жмем `F2`, для закрытия после сохранения файла жмем `F10`.

		`Содержимое файла test_vim.txt перед закрытием с сохранением.`
		![./Screenshots/part7_VIM.png](./Screenshots/part7_VIM.png)

		`Содержимое файла test_nano.txt перед закрытием с сохранением.`
		![./Screenshots/part7_NANO.png](./Screenshots/part7_NANO.png)

		`Содержимое файла test_mcedit.txt перед сохранением.`
		![./Screenshots/part7_MCEDIT_before_save.png](./Screenshots/part7_MCEDIT_before_save.png)

		`Содержимое файла test_mcedit.txt перед закрытием.`
		![./Screenshots/part7_MCEDIT_after_save.png](./Screenshots/part7_MCEDIT_after_save.png)

	3.	Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку 
		"21 School 21", закройте файл без сохранения изменений.
		- VIM. Чобы начать редактировать файл жмем `i`. Для выхода из режима печати нажимаем `Esc`, далее вводим `:q!` и нажимаем на `Enter`.
			`Содержимое файла test_vim.txt перед закрытием без сохранения.`
			![./Screenshots/part7.1_VIM.png](./Screenshots/part7.1_VIM.png)
			
		- NANO. Для выхода без сохранения жмем `ctrl + x` и далее `n`.
			`Содержимое файла test_nano.txt перед закрытием без сохранения.`
			![./Screenshots/part7.1_NANO.png](./Screenshots/part7.1_NANO.png)
			
		- MCEDIT. Для выхода без сохранения жмем `F10` клавишей `<-` передвигаем на "No" и далее Жмем `Enter`.
			`Содержимое файла test_mcedit.txt после редактирования.`
			![./Screenshots/part7.1_MCEDIT.png](./Screenshots/part7.1_MCEDIT.png)
			
			`Содержимое файла test_mcedit.txt перед закрытием без сохранения.`
			![./Screenshots/part7.1_1_MCEDIT.png](./Screenshots/part7.1_1_MCEDIT.png)
			
	4.	Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции 
		поиска по содержимому файла (слово) и замены слова на любое другое.
		- VIM. 
			- Для возможности поиска слова нужно быть в нормальный режим. Чтобы вернуться в нормальный режим после режима редактирования, нажмите
			  клавишу Esc. Для поиска всего слова начните поиск, нажав `/`, введите слово чтобы выполнить поиск. Найденное слово будет выделено в тексте.
			
				`VIM. Результат поиска слова.`
				![./Screenshots/part7.2_VIM.png](./Screenshots/part7.2_VIM.png)
			- Для поиска слова с заменой на другое используем Команду `:s/Sber/Sberbank/`.
				`VIM. Результат поиска и замены слова перед применением.`
				![./Screenshots/part7.3_VIM.png](./Screenshots/part7.3_VIM.png)
				
				`VIM. Результат поиска и замены слова после применения.`
				![./Screenshots/part7.3_1_VIM.png](./Screenshots/part7.3_1_VIM.png)
		- NANO.
			- Для поиска слова вводим команду `ctrl + w`, введите слово чтобы выполнить поиск и нажмите `Enter`.
			
				`NANO. Результат поиска слова.`
				![./Screenshots/part7.2_NANO.png](./Screenshots/part7.2_NANO.png)
				
			- Для поиска слова с заменой на другое используем команду `ctrl + \School` и жмем на `Enter`.
			  Далее вводим заменяющее слово `Univercity` и жмем на `Enter`. Для подтверждения жмем на `y`.
				`VIM. Результат поиска слова, которое планируется заменить.`
				![./Screenshots/part7.3_1_NANO.png](./Screenshots/part7.3_1_NANO.png)
				
				`VIM. Слово, на которое меняем.`
				![./Screenshots/part7.3_2_NANO.png](./Screenshots/part7.3_2_NANO.png)
				`VIM. Результат после замены слова.`
				![./Screenshots/part7.3_3_NANO.png](./Screenshots/part7.3_3_NANO.png)
				
		- MCEDIT.
			- Сначала редактируем файл (так просят в задании) и сохраняем. Далее выходим из файла. Открываем и ищем. Поиск выполняется командой `F7`,
			  печатаем искомое слово и жмем на `Ok`. Только в таком случае слово находится как слово, а не как строка (
			  как, например, в случае поиска через `Find all`).
			  
				`Результат поиска слова`
				![./Screenshots/part7.3_MCEDIT.png](./Screenshots/part7.3_MCEDIT.png)
			  
			- Замена слова производится нажатием на кнопку `F4`. Далее вводим заменяемое слово, потом заменяющее и жмем на кнопку `Ok` 
			  и подтверждаем кнопкой `Replace`.
			  
				`Замена слова`
				![./Screenshots/part7.3_1_MCEDIT.png](./Screenshots/part7.3_1_MCEDIT.png)
				
				`Подтверждение замены слова`
				![./Screenshots/part7.3_2_MCEDIT.png](./Screenshots/part7.3_2_MCEDIT.png)
				
				`результат подтверждения`
				![./Screenshots/part7.3_3_MCEDIT.png](./Screenshots/part7.3_3_MCEDIT.png)
				
				`Сохранение файла после замены слова`
				![./Screenshots/part7.3_4_MCEDIT.png](./Screenshots/part7.3_4_MCEDIT.png)
## Part 8.  Установка и базовая настройка сервиса SSHD
---
	1.	Установить службу SSHd.
		- Для скачивания и установки службы используем команду `sudo apt install openssh-server`, далее подтверждаем установку нажатием на `y`.
			![./Screenshots/part8.png](./Screenshots/part8.png)
			
		- Попутно проверяем установилась ли клиентская часть, введу команду `sudo apt-get install openssh-client`.
			![./Screenshots/part8.1.png](./Screenshots/part8.1.png)
	2.	Добавить автостарт службы при загрузке системы.
		
		`Добавление производится командой указанной на скриншоте`
		![./Screenshots/part8.2.png](./Screenshots/part8.2.png)
	3.	Перенастроить службу SSHd на порт 2022.
		- Прежде чем перенастроить службу SSHd на порт 2022 сделаем его копию и защитим его от записи с помощью следующих команд:
			```
			sudo cp /etc/ssh/sshd_config /etc/ssh/sshd_config.original
			sudo chmod a-w /etc/ssh/sshd_config.original
			```
			![./Screenshots/part8.3.png](./Screenshots/part8.3.png)
			
		- Далее открываем конфигурационный файл в любом текстовом редакторе, например `sudo vi /etc/ssh/sshd_config`, меняем порт и сохраняем.
		
			![./Screenshots/part8.3.1.png](./Screenshots/part8.3.1.png)
			
		- Для применения сохраненных настроек требуется перезапуск серверного приложения командой `service ssh restart`
			
			![./Screenshots/part8.3.2png](./Screenshots/part8.3.2.png)
		
	4.	Используя команду ps, показать наличие процесса sshd. Для этого к команде нужно подобрать ключи.
	
		Для вывода используем команду `ps -C sshd`.
		![./Screenshots/part8.4.png](./Screenshots/part8.4.png)
		
		```
		ps - выводит список текущих процессов на сервере. Флаги:
		-A, -e, (a) - выбрать все процессы;
		-a - выбрать все процессы, кроме фоновых;
		-d, (g) - выбрать все процессы, даже фоновые, кроме процессов сессий;
		-N - выбрать все процессы кроме указанных;
		-С - выбирать процессы по имени команды;
		-G - выбрать процессы по ID группы;
		-p, (p) - выбрать процессы PID;
		--ppid - выбрать процессы по PID родительского процесса;
		-s - выбрать процессы по ID сессии;
		-t, (t) - выбрать процессы по tty;
		-u, (U) - выбрать процессы пользователя.
		```
		- Вызов команды `netstat -tan`
			![./Screenshots/part8.4.1.png](./Screenshots/part8.4.1.png)
			
		```
		-a - Отображение всех подключений и ожидающих портов
		-n - Отображение адресов и номеров портов в числовом формате
		-t - Отображение текущего подключения в состоянии переноса нагрузки с процессора на сетевой адаптер при передаче данных ( "offload" )
		0.0.0.0 означает адрес устройства по умолчанию не подключенного к сети.
		LISTEN - готовность к установке соединения между компьютерами, с сервером.
		```
		
	5.	Перезагрузить систему.
		- Для перезагрузки используем команду `service ssh restart`
		
		
## Part 9. Установка и использование утилит top, htop
---
	1.	Установить и запустить утилиты top и htop.
		
		![./Screenshots/part9.png](./Screenshots/part9.png)
		
		- По выводу команды top определить и написать в отчёте:
			- Общий вид диспетчера задач
				![./Screenshots/part9.png](./Screenshots/part9.png)
			- uptime
				![./Screenshots/part9.1.png](./Screenshots/part9.1.png)
			
			- количество авторизованных пользователей`
				![./Screenshots/part9.2.png](./Screenshots/part9.2.png)
			
			- общую загрузку системы
				![./Screenshots/part9.3.png](./Screenshots/part9.3.png)
				
			- общее количество процессов
				![./Screenshots/part9.4.png](./Screenshots/part9.4.png)
				
			- загрузку cpu	
				![./Screenshots/part9.5.png](./Screenshots/part9.5.png)
				
			- загрузку памяти
				![./Screenshots/part9.6.png](./Screenshots/part9.6.png)
				
			- pid процесса занимающего больше всего памяти
				![./Screenshots/part9.7.png](./Screenshots/part9.7.png)
			
			- pid процесса, занимающего больше всего процессорного времени
				![./Screenshots/part9.8.png](./Screenshots/part9.8.png)
		- В отчёт вставить скрин с выводом команды htop:
			- отсортированному по PID, PERCENT_CPU, PERCENT_MEM, TIME
			> Для сортировки используем жмем на F6 и стрелками вверх-вниз выбираем нужный параметр, по которому мы хотим сделать сортировку.
			
				`Сортировка по PID`
				![./Screenshots/part9.01.png](./Screenshots/part9.01.png)
				
				`Сортировка по PERCENT_CPU`
				![./Screenshots/part9.02.png](./Screenshots/part9.02.png)
				
				`Сортировка по PERCENT_MEM`
				![./Screenshots/part9.03.png](./Screenshots/part9.03.png)
				
				`Сортировка по TIME`
				![./Screenshots/part9.04.png](./Screenshots/part9.04.png)
				
				`отфильтрованному для процесса sshd`
				![./Screenshots/part9.05.png](./Screenshots/part9.05.png)
				
				`с процессом syslog, найденным, используя поиск`
				![./Screenshots/part9.06.png](./Screenshots/part9.06.png)
				
				`с добавленным выводом hostname, clock и uptime; добавление делаем через F2 и далее используем стрелки для выбора`
				![./Screenshots/part9.07.png](./Screenshots/part9.07.png)
				
## Part 10. Использование утилиты fdisk
---
	>	Теперь давай разберёмся, как получить информацию о жёстком диске. Специально для тебя я собрал пару примеров работы с утилитой fdisk.
	
	1.	Запустить команду fdisk -l.
		![./Screenshots/part10.png](./Screenshots/part10.png)
		
		- Название жесткого диска `/dev/sda`
		- Размер жесткого диска `10 GIB`
		- Количество секторов `19103744`
		![./Screenshots/part10.1.png](./Screenshots/part10.1.png)
		
		- Размер `Swap`
		![./Screenshots/part10.2.png](./Screenshots/part10.2.png)
		
## Part 11. Использование утилиты df
---
	1.	Запустить команду df.
		- В отчёте написать для корневого раздела (/):

			- размер раздела - 9299276
			- размер занятого пространства - 4290544
			- размер свободного пространства - 3884756
			- процент использования 56%
			![./Screenshots/part11.png](./Screenshots/part11.png)

		- Определить и написать в отчёт единицу измерения в выводе.
			- Единица измерения `Кб`
	
	2.	Запустить команду df -Th.
		- В отчёте написать для корневого раздела (/):

			- размер раздела - 8.9
			- размер занятого пространства - 4.7
			- размер свободного пространства - 3.8
			- процент использования - 56%
			![./Screenshots/part11.png](./Screenshots/part11.png)
			
		- Определить и написать в отчёт тип файловой системы для раздела.
			- Тип файловой системы для раздела - ext4

## Part 12. Использование утилиты du
---
	> df - не единственный способ поучить информацию о дисковом пространстве. Сейчас расскажу про ещё один.
	
	1.	Запустить команду du
		![./Screenshots/part12.png](./Screenshots/part12.png)
		
	2.	Вывести размер папок /home, /var, /var/log (в байтах, в человекочитаемом виде)
		![./Screenshots/part12.1.png](./Screenshots/part12.1.png)
	
	3.	Вывести размер всего содержимого в /var/log (не общее, а каждого вложенного элемента, используя *)
		![./Screenshots/part12.2.png](./Screenshots/part12.2.png)
		
## Part 13. Установка и использование утилиты ncdu
---
	1.	Установить утилиту ncdu.
		`sudo apt install ncdu`
		![./Screenshots/part13.png](./Screenshots/part13.png)
		
	2.	Вывести размер папок /home, /var, /var/log.
		
		`ncdu /home`
		![./Screenshots/part13.1.png](./Screenshots/part13.1.png)
		
		`ncdu /var`
		![./Screenshots/part13.2.png](./Screenshots/part13.2.png)
		
		`ncdu /var/log`
		![./Screenshots/part13.3.png](./Screenshots/part13.3.png)
		
## Part 14. Работа с системными журналами
---
	1.	Открыть для просмотра системные журналы:
		`cat /var/log/dmesg`
		![./Screenshots/part14.png](./Screenshots/part14.png)
		
		`cat /var/log/syslog`
		![./Screenshots/part14.1.png](./Screenshots/part14.1.png)
		
		`cat /var/log/auth.log`
		![./Screenshots/part14.2.png](./Screenshots/part14.2.png)
		
		- Перезапуск службы SSHd `sudo systemctl restart ssh.service`
			
			`Сообщение о рестарте службы`
			![./Screenshots/part14.3.png](./Screenshots/part14.3.png)
			
## Part 15. Использование планировщика заданий CRON
---
	`crontab -e`
	![./Screenshots/part15.png](./Screenshots/part15.png)
	
	`cat /var/log/syslog`
	![./Screenshots/part15.1.png](./Screenshots/part15.1.png)
		