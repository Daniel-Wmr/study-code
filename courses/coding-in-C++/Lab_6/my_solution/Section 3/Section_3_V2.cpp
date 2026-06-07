#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Device
{
protected:
    std::string name;
    bool power_status = false;

public:
    Device(const std::string& name)
        : name(name){}
        
    virtual ~Device()
    {
        std::cout << "Device destroyed: " << name << std::endl;
    }

    void turn_on()
    {
        power_status = true;
    }

    void turn_off()
    {
        power_status = false;
    }

    std::string get_name() const
    {
        return name;
    }

    virtual std::string get_type() const = 0;

    void print_info() const
    {
        std::cout << "Device name: " << name << std::endl;
        std::cout << "Type: " << get_type() << std::endl;
        std::cout << "Power: " << (power_status ? "On" : "Off") << std::endl;
    }
};

class Speaker : public Device
{
public:
    Speaker(const std::string& name)
        : Device(name){}

    std::string get_type() const override
    {
        return "Speaker";
    }

    ~Speaker() = default;
};

class Microphone : public Device
{
public:
    Microphone(const std::string& name)
        : Device(name){}

    std::string get_type() const override
    {
        return "Microphone";
    }

    ~Microphone() = default;
};

class Display : public Device
{
public:
    Display(const std::string& name)
        : Device(name){}

    std::string get_type() const override
    {
        return "Display";
    }

    ~Display() = default;
};

class SharedDevice : public Device
{
protected:
    const std::string ip_address;
    bool connection_status = false;

public:
    SharedDevice(const std::string& name, const std::string& ip_address, bool connection_status)
        : Device(name), ip_address(ip_address), connection_status(connection_status){}

    void connect_to_network()
    {
        connection_status = true;
    }

    void disconnect_from_network()
    {
        connection_status = false;
    }

    void print_network_info() const
    {
        print_info();
        std::cout << "IP adress: " << ip_address << std::endl;
        std::cout << "Connection status: " << (connection_status ? "Connected" : "Disconnected") << std::endl;
    }

    virtual ~SharedDevice()
    {
        std::cout << "SharedDevice deleted..." << std::endl;
    }
};

class NetworkStorage : public SharedDevice
{
public:
    NetworkStorage(const std::string& name, const std::string& ip_address, bool connection_status)
        : SharedDevice(name, ip_address, connection_status){}

    std::string get_type() const override
    {
        return "Network Storage";
    }

    ~NetworkStorage() = default;
};

class MusicServer : public SharedDevice
{
public:
    MusicServer(const std::string& name, const std::string& ip_address, bool connection_status)
        : SharedDevice(name, ip_address, connection_status){}

    std::string get_type() const override
    {
        return "Music Server";
    }

    ~MusicServer() = default;
};

class NAS : public SharedDevice
{
public:
    NAS(const std::string& name, const std::string& ip_address, bool connection_status)
        : SharedDevice(name, ip_address, connection_status){}

    std::string get_type() const override
    {
        return "NAS";
    }

    ~NAS() = default;
};

class Room
{
private:
    std::string name;
    std::vector<std::unique_ptr<Device>> unique_devices;
    std::vector<std::shared_ptr<SharedDevice>> shared_devices;
    
public:
    Room(std::string name)
        : name(name){}

    void add_unique_device(std::unique_ptr<Device> device)
    {
        unique_devices.push_back(std::move(device));
    }

    void add_shared_device(std::shared_ptr<SharedDevice> device)
    {
        shared_devices.push_back(device);
    }

    void remove_device_by_name(const std::string& name);
    void print_devices() const;
};

void Room::remove_device_by_name(const std::string& name)
{
    auto it1 = std::find_if(
        unique_devices.begin(), 
        unique_devices.end(),
        [&name](std::unique_ptr<Device>& device)
        {
            return device->get_name() == name;
        });

    if (it1 != unique_devices.end())
    {
        unique_devices.erase(it1);
        return;
    }
    else
    {
        auto it2 = std::find_if(
            shared_devices.begin(),
            shared_devices.end(),
            [&name](std::shared_ptr<SharedDevice>& device)
            {
                return device->get_name() == name;
            });
        
        if (it2 != shared_devices.end())
        {
            shared_devices.erase(it2);
            return;
        }
    }

    std::cout << "Device " << name << " not found..." << std::endl;
}

void Room::print_devices() const
{
    std::cout << "=== Room: " << name << " ===" << std::endl;
    std::cout << "=== Unique Devices ===" << std::endl;

    for (const auto& device : unique_devices)
    {
        device->print_info();
        std::cout << std::endl;
    }

    std::cout << "\n=== Shared Devices ===" << std::endl;

    for (const auto& device : shared_devices)
    {
        device->print_network_info();
        std::cout << std::endl;
    }
}

int main()
{
    auto nas = std::make_shared<NAS>(
        "Central NAS",
        "192.168.0.10",
        false);

    std::cout << "\n=== Shared Pointer Counter Test ===\n";

    std::cout << "After creation: "
              << nas.use_count()
              << std::endl;

    {
        Room living_room("Living Room");
        Room studio("Recording Studio");

        auto speaker =
            std::make_unique<Speaker>("JBL Speaker");

        auto microphone =
            std::make_unique<Microphone>("Rode Microphone");

        auto display =
            std::make_unique<Display>("Samsung Display");

        living_room.add_unique_device(std::move(speaker));
        studio.add_unique_device(std::move(microphone));
        living_room.add_unique_device(std::move(display));

        if (!speaker)
        {
            std::cout << "speaker is now nullptr\n";
        }

        if (!microphone)
        {
            std::cout << "microphone is now nullptr\n";
        }

        if (!display)
        {
            std::cout << "display is now nullptr\n";
        }

        living_room.add_shared_device(nas);

        std::cout << "After adding to living room: "
                  << nas.use_count()
                  << std::endl;

        studio.add_shared_device(nas);

        std::cout << "After adding to studio: "
                  << nas.use_count()
                  << std::endl;

        nas->connect_to_network();

        std::cout << "\n=== Living Room ===\n";
        living_room.print_devices();

        std::cout << "\n=== Studio ===\n";
        studio.print_devices();

        std::cout << "\nRemoving JBL Speaker...\n";
        living_room.remove_device_by_name("JBL Speaker");

        std::cout << "\n=== Living Room After Removal ===\n";
        living_room.print_devices();

        std::cout << "\nCount before rooms are destroyed: "
                  << nas.use_count()
                  << std::endl;
    }

    std::cout << "\nAfter rooms are destroyed: "
              << nas.use_count()
              << std::endl;

    return 0;
}