# brightnessCtl

Wrote this proram after loosing Brightness control some day doing updates on my Laptop.
Thanks you /sys/class!

## Compile

```
  gcc -o brightness brightness.c
```

## Permissions

Don't forget to give SUID to the `brightness` program. Only root can write `/sys/class`!

```
  chown root:root brightness
  chmod u+s brightness
```

## i3 integration

```
  bindsyn XF86MonBrightnessDown exec /home/henrylf/bin/brightness dec

  bindsyn XF86MonBrightnessUp exec /home/henrylf/bin/brightness inc

```
