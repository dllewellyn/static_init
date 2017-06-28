Implements a basic callback to execute code pre-main. Can be modified to allow for creating modular systems with
self-registering modules.

Components:

* hello.cpp - this is where the static execute happens in the lines:

```
extern "C" void reg(int moduleId);

int registerModule() {
	reg(1);
	return 1;
}

static int x = registerModule();

```

x will be initialised before main, meaning registerModule will be called. This in turn calls through to reg (and passes
1 in). Which will call through to:

```
#[no_mangle]
pub extern fn reg(module_id: u8) {
    println!("Registered {}", module_id);
}
```

Where (in a modular system) you could register that module. Further work from here to pass the module_id from rust, and
to expand this to allow for passing a function pointer to the reg function.