# Simple Linux tips

<!-- toc -->

- [WSL](#wsl)
  * [Make /etc/resolv.conf changes permanent in WSL 2](#make-etcresolvconf-changes-permanent-in-wsl-2)
  * [Limit resource usage by WSL](#limit-resource-usage-by-wsl)
  * [Resources](#resources)

<!-- tocstop -->

## WSL 

### Make /etc/resolv.conf changes permanent in WSL 2

```
sudo rm /etc/resolv.conf
sudo bash -c 'echo "nameserver 192.168.8.1" > /etc/resolv.conf'
sudo bash -c 'echo "nameserver 8.8.8.8" >> /etc/resolv.conf'
sudo bash -c 'echo "[network]" > /etc/wsl.conf'
sudo bash -c 'echo "generateResolvConf = false" >> /etc/wsl.conf'
sudo chattr +i /etc/resolv.conf
```

### Remove the Win's PATH from WSL

```
sudo bash -c 'echo "[interop]" >> /etc/wsl.conf'
sudo bash -c 'echo "appendWindowsPath = false" >> /etc/wsl.conf'
```

### Limit resource usage by WSL

Edit `C:\Users\<UserName>\.wslconfig` and put in there:

```
[wsl2]
memory=4GB 
processors=2
```


### Resources

[Advanced settings configuration in WSL](https://learn.microsoft.com/en-us/windows/wsl/wsl-config#configure-global-options-with-wslconfig)