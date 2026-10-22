use clap::Parser;
use ironi;

fn main() {
    let args = ironi::Args::parse();

    if let Err(e) = ironi::run(args) {
        eprintln!("{}", e);
    };
}
