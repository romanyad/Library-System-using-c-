.PHONY: clean All

All:
	@echo "----------Building project:[ final - Release ]----------"
	@cd "final" && "$(MAKE)" -f  "final.mk"
clean:
	@echo "----------Cleaning project:[ final - Release ]----------"
	@cd "final" && "$(MAKE)" -f  "final.mk" clean
