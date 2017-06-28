#[no_mangle]
pub extern fn reg(module_id: u8) {
    println!("Registered {}", module_id);
}

fn main() {
    println!("Hello, world!");
}
